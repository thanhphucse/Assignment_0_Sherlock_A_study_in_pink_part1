/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

int firstMeet(int& EXP1, int& EXP2, const int& E1){
    if (E1 < 0 || E1>999) {
        return -999;
    }
    else {
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 900) EXP1 = 900;
        if (EXP2 < 0) EXP2 = 0;
        if (EXP2 > 900) EXP2 = 900;
        
        if (E1 >= 0 && E1 <= 399) {
            if (E1 >= 0 && E1 <= 49) {
                EXP2 = EXP2 + 25;
            }
            if (E1 >= 50 && E1 <= 99) {
                EXP2 = EXP2 + 50;
            }
            if (E1 >= 100 && E1 <= 149) {
                EXP2 = EXP2 + 85;
            }
            if (E1 >=150 && E1 <= 199) {
                EXP2 = EXP2 + 25 + 50;
            }
            if (E1>=200 && E1 <= 249) {
                EXP2 = EXP2 + 25 + 85;
            }
            if (E1>=250 && E1 <= 299) {
                EXP2 = EXP2 + 50 + 85;
            }
            if (E1>=300 && E1 <= 399) {
                EXP2 = EXP2 + 25 + 50 + 85;
            }
            
            if (E1 % 2 == 0) {
                EXP1 = ceil(EXP1 - (float)E1 / 5);
            }
            else {
                EXP1 = ceil(EXP1 + (float)E1 / 10);
            }
        }
        else {
            if (E1>=400 && E1 <= 499) {
                EXP2 = ceil(EXP2 + ((float)E1 / 7 + 9));
            }
            if (E1>=500 && E1 <= 599) {
                EXP2 = ceil(EXP2 + ((float)E1 / 9 + 11));
            }
            if (E1>=600 && E1 <= 699) {
                EXP2 = ceil(EXP2 + ((float)E1 / 5 + 6));
            }
            if (E1>=700 && E1 <= 799) {
                EXP2 = ceil(EXP2 + ((float)E1 / 7 + 9));
                if (EXP2 > 200) {
                    EXP2 = ceil(EXP2 + ((float)E1 / 9 + 11));
                }
            }
            if (E1>=800 && E1 <= 999) {
                EXP2 = ceil(EXP2 + ((float)E1 / 7 + 9));
                EXP2 = ceil(EXP2 + ((float)E1 / 9 + 11));
                if (EXP2 > 600) {
                    EXP2 = ceil(EXP2 + ((float)E1 / 5 + 6));
                    EXP2 = ceil(EXP2 * 1.15);
                }
            }

            EXP1 = ceil(EXP1 - 0.1 * E1);
        }
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 900) EXP1 = 900;
        if (EXP2 < 0) EXP2 = 0;
        if (EXP2 > 900) EXP2 = 900;
        return EXP1 + EXP2;
    }
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    if (E2 < 0 || E2>999) {
        return -999;
    }
    else {
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 900) EXP1 = 900;
        if (EXP2 < 0) EXP2 = 0;
        if (EXP2 > 900) EXP2 = 900;
        if (HP2 < 0) HP2 = 0;
        if (HP2 > 999) HP2 = 999;
        if (M2 < 0) M2 = 0;
        if (M2 > 2000) M2 = 2000;

        if (0 <= E2 && E2 <= 299) {
            EXP2 = ceil(EXP2 + ((float)E2 / 9 + 10));
            EXP1 = ceil(EXP1 + ((float)E2 / 9 + 10) / 3);
        }
        if (300 <= E2 && E2 <= 499) {
            EXP2 = ceil(EXP2 + ((float)E2 / 9 + 10));
            EXP1 = ceil(EXP1 + ((float)E2 / 9 + 10) / 3);

            EXP2 = ceil(EXP2 + 0.35 * E2);
            EXP1 = ceil(EXP1 + (0.35 * E2) / 3);
        }
        if (500 <= E2 && E2 <= 999) {
            EXP2 = ceil(EXP2 + ((float)E2 / 9 + 10));
            EXP1 = ceil(EXP1 + ((float)E2 / 9 + 10) / 3);

            EXP2 = ceil(EXP2 + 0.35 * E2);
            EXP1 = ceil(EXP1 + (0.35 * E2) / 3);

            float d = 0.17 * (((float)E2 / 9 + (float)10) + (0.35 * E2));
            EXP2 = ceil(EXP2 + d);
            EXP1 = ceil(EXP1 + d / 3);
        }
        HP2 = ceil(HP2 - pow(E2, 3) / pow(2, 23));
        if (E2 % 2 == 0) {
            M2 = ceil(M2 + pow(E2, 2) / (float)50);
        }
        if (EXP1 > 900) EXP1 = 900;
        if (EXP2 > 900) EXP2 = 900;
        if (HP2 < 0) HP2 = 0;
        if (M2 > 2000) M2 = 2000;
        return EXP2 + HP2 + M2 + EXP1;
    }
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    if (E3 < 0 || E3>999) {
        return -999;
    }
    else {
        if (HP1 < 0) HP1 = 0;
        if (HP1 > 999) HP1 = 999;
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 900) EXP1 = 900;
        if (M1 < 0) M1 = 0;
        if (M1 > 2000) M1 = 2000;   
        //con duong 1
        int k1 = 0;
        int P1[9] = { 1,3,5,7,9,11,13,15,17 };
        for (int i = 0; i <= 8; ++i) {
            P1[i] = (P1[i] + E3) % 26 + 65;
            if (P1[i] == 80) {
                k1 = i + 1;
                break;
            }
        }
        if (k1 == 0) {
            M1 = ceil(M1 - (pow(9, 2) * E3) / (float)9);
            if (M1 < 0) M1 = 0;
        }
        else {
            HP1 = ceil(HP1 - (float)80 * k1 * 2);
            if (HP1 < 0) HP1 = 0;
            EXP1 = ceil(EXP1 + (1000 - 80 * k1) % 101);
            if (EXP1 > 900) EXP1 = 900;
            M1 = ceil(M1 - (k1 * E3) / (float) 9);
            if (M1 < 0) M1 = 0;
        }
        // con duong 2
        int k2 = 0;
        int s = 0;
        int m = 0;
        int P2[7] = { 2,3,5,7,11,13,17 };
        for (int i = 0; i <= 6; ++i) {
            P2[i] = (P2[i] + E3) % 26;
            s = s + P2[i];
        }
        m = ceil((float)s / 7);
        for (int i = 0; i <= 6; ++i) {
            P2[i] = (P2[i] + s + m) % 26 + 65;
            if (P2[i] == 80) {
                k2 = i + 1;
                break;
            }
        }
        if (k2 == 0) {
            M1 = ceil(M1 - (pow(7, 2) * E3) / (float)9);
            if (M1 < 0) M1 = 0;
        }
        else {
            HP1 = ceil(HP1 - (float)80 * k2 * 2);
            if (HP1 < 0) HP1 = 0;
            EXP1 = ceil(EXP1 + (1000 - 80 * k2) % 101);
            if (EXP1 > 900) EXP1 = 900;
            M1 = ceil(M1 - (k2 * E3) / (float)9);
            if (M1 < 0) M1 = 0;
        }
        //con duong 3
        int max = 4;
        int k3 = 0;
        int P3[20] = { 4,16,36,64,100,144,196,256,324,400,484,576,676,784,900,1024,1156,1296,1444,1600 };
        for (int i = 0; i <= 19; ++i) {
            P3[i] = (P3[i] + E3 * E3) % 113;
            if (P3[i] >= max) max = P3[i];
        }

        for (int i = 19; i>=0; --i) {
            int temp3 = ceil((P3[i] + E3) / (float)max);
            P3[i] = temp3 % 26 + 65;
            if (P3[i] == 80) {
                k3 = 20 - i;
                break;
            }
        }
        if (k3 == 0) {
            M1 = ceil(M1 - (pow(20, 2) * E3) / (float)9);
            if (M1 < 0) M1 = 0;
        }
        else {
            M1 = ceil(M1 - k3 * E3 / (float)9);
            if (M1 < 0) M1 = 0;
            HP1 = ceil(HP1 - (float)80 * k3 * 3);
            if (HP1 < 0) HP1 = 0;
            EXP1 = ceil(EXP1 + (3500 - 80 * k3) % 300);
            if (EXP1 > 900) EXP1 = 900;
        }
        //con duong 4
        int P4[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        int min = 10;
        int min_idx = 0;
        int k4 = 0;
        int temp4 = ceil((float)E3 / 29);
        temp4 = pow(temp4, 3);
        for (int i = 0; i <= 11; ++i) {
            P4[i] = (P4[i] + temp4) % 9;
            if (P4[i] <= min) min = P4[i];
        }
        for (int i = 0; i <= 11; ++i) {
            if (P4[i] == min) {
                min_idx = i + 1;
                break;
            }
        }
        int temp = ceil((min / (float)min_idx));
        for (int i = 11; i >= 0; --i) {

            P4[i] = ((P4[i] + E3) * temp) % 26 + 65;
            if (P4[i] == 80) {
                k4 = 12 - i;
                break;
            }
        }
        if (k4 == 0) {
            M1 = ceil(M1 - (pow(12, 2) * E3) / (float)9);
            if (M1 < 0) M1 = 0;
        }
        else {
            HP1 = ceil(HP1 - 80 * k4 * 4);
            if (HP1 < 0) HP1 = 0;
            EXP1 = ceil(EXP1 + (4500 - 80 * k4) % 400);
            if (EXP1 > 900) EXP1 = 900;
            M1 = ceil(M1 - k4 * E3 / (float)9);
            if (M1 < 0) M1 = 0;
        }

        if (k1 == 0 && k2 == 0 && k3 == 0 && k4 == 0) {
            HP1 = ceil(HP1 - (59 * E3) % 900);
            if (HP1 < 0) HP1 = 0;
            EXP1 = ceil(EXP1 - (79 * E3) % 300);
            if (EXP1 < 0) EXP1 = 0;
            return -1;
        }
        return HP1 + EXP1 + M1;
    }
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
