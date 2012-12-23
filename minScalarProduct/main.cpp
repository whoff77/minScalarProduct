#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

void buildVectors();
void quickSortVectors();
void quickSort(vector<long long> &, int, int);
void partition(vector<long long> &, int, int, int &);
void displayVectors();
void findMinProduct();


// ***CHANGE "LONG LONG's" to INTS IF DOING SHORTER NUMBERS***
int cases = 0, vectorSize = 0/*, item = 0, minProduct*/;
long long item = 0, minProduct = 0;
vector<long long> intVector1, intVector2;
string infileName = "largeIn.in", outfileName = "largeOut.out";
ifstream infile(infileName.c_str());
ofstream outfile(outfileName.c_str());

int main() {

	clock_t tStart = clock();

	infile >> cases;
	for (int i = 1; i <= cases; i++) {
		buildVectors();
		quickSortVectors();
		findMinProduct();
		//cout << i << " " << minProduct << endl;
		outfile << "Case #" << i << ": " << minProduct << endl;
		intVector1.clear();
		intVector2.clear();
	}

	infile.close();
	outfile.close();
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	cin.get();
	return 0;
}

void buildVectors() {
	
	infile >> vectorSize;

	for (int i = 0; i < vectorSize; i++) {
		infile >> item;
		intVector1.push_back(item);
	}
	for (int i = 0; i < vectorSize; i++) {
		infile >> item;
		intVector2.push_back(item);
	}

	//displayVectors();
}

void quickSortVectors() {
	quickSort(intVector1, 0, vectorSize-1);
	quickSort(intVector2, 0, vectorSize-1);
	//displayVectors();
}
void quickSort(vector<long long> &theVector, int first, int last) {
	if (first < last) {
		int pivotIndex;
		// Partition the array into two sets.
		partition(theVector, first, last, pivotIndex);
		// Sort both sets recursively
		quickSort(theVector, first, pivotIndex - 1);
		quickSort(theVector, pivotIndex + 1, last);
	}
}
void partition(vector<long long> &theVector, int first, int last, int &pivotIndex) {
	swap(theVector[(first+last)/2], theVector[first]);
	long long pivot = theVector[first]; // select first element as pivot (bad choice?)
	int firstUnknown = first + 1; // first is the pivot
	int lastUnknown = last;
	// As long as we haven't reached the last unknown,
	// swap the element if it belongs in the second part of the array.
	while (firstUnknown <= lastUnknown) {
		if (theVector[firstUnknown] >= pivot) {
			swap(theVector[firstUnknown], theVector[lastUnknown]);
			lastUnknown--;
		}
		else firstUnknown++;
	}
	// Move the pivot to the spot between the partitioned sets.
	swap(theVector[first], theVector[lastUnknown]);
	pivotIndex = lastUnknown;
}

void displayVectors() {
	cout << "vector1: ";
	for (int i = 0; i < vectorSize; i++) cout << intVector1[i] << " ";
	cout << endl;
	cout << "vector2: ";
	for (int i = 0; i < vectorSize; i++) cout << intVector2[i] << " ";
	cout << endl;
}

void findMinProduct() {
	minProduct = 0;
	for (int i = 0; i < vectorSize; i++)
		minProduct += intVector1[i] * intVector2[vectorSize-1-i];
}