// Math_chain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>

// #include <ctime>
#include "Windows.h"
#include "Winbase.h"

void InitRand()
{
//	srand(time(0));
	srand(GetTickCount());
}

const int kValMin = 0;
const int kValMax = 10;

const int kOp = 9;
const int kChains = 6;

void ShowParameters()
{
	using namespace std;

	cout << "Welcome to Math Chain 1.0!" << endl;
	cout << "   Min:    " << kValMin << endl;
	cout << "   Max:    " << kValMax << endl;
	cout << "   Length: " << kOp << endl;
	cout << "   Chains: " << kChains << endl;
	cout << endl;
}

int GetNewVal()
{
	return kValMin + (rand() % (kValMax - kValMin + 1));
}

void ForgeChain(std::ofstream& fExercises, std::ofstream& fAnswers)
{
	using namespace std;

	int val = GetNewVal();

	cout << "The chain: " << val;
	fExercises << "The chain: " << val;
	fAnswers << "The chain: " << val;

	for(int i = 0; i < kOp; i++)
	{
		int nextVal = GetNewVal();

		enum { eAdd, eSub } op;

		// Decide what is a operation to use.
		if(nextVal == val)
		{
			op = (rand()&1) ? eAdd : eSub;
//			// Skip null operation.
// 			i--;
// 			continue;
		}
		else
			op = (nextVal > val) ? eAdd : eSub;

		// Print next operation and operand.
		if(op == eAdd)
		{
			cout << " + " << nextVal - val;
			fExercises << " + " << nextVal - val;
			fAnswers << " + " << nextVal - val;
		}
		else
		{
			cout << " - " << val - nextVal;
			fExercises << " - " << val - nextVal;
			fAnswers << " - " << val - nextVal;
		}

		cout << "(" << nextVal << ")";
		fExercises << "(   )";
		fAnswers << "(" << nextVal << ")";
		val = nextVal;
	}

	//	cout << " =" << endl;
	cout << endl;
	fExercises << endl;
	fAnswers << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	InitRand();

	// Init file streams.
	ofstream fExercises("exercises.txt");
	ofstream fAnswers("answers.txt");
	
// 	ofstream fExercises;
// 	fExercises.open("exercises.txt");
// 	ofstream fAnswers;
// 	fAnswers.open("answers.txt");
	
	ShowParameters();

	for(int i = 0; i < kChains; i++)
		ForgeChain(fExercises, fAnswers);

// 	fExercises.close();
// 	fAnswers.close();

	return 0;
}

