$NetBSD: patch-scribus_util.cpp,v 1.1 2017/02/21 16:01:36 joerg Exp $

Simplify logic to avoid expensive nested loop handling in Clang.

--- scribus/util.cpp.orig	2017-02-21 14:56:16.278339690 +0000
+++ scribus/util.cpp
@@ -1412,15 +1412,15 @@ const QString arabicToRoman(uint i)
 	roman += "m";
 	arabic -= 1000000;
 	}
-	while (arabic - 900000 >= 0){
+	if (arabic - 900000 >= 0){
 	roman += "cm";
 	arabic -= 900000;
 	}
-	while (arabic - 500000 >= 0){
+	if (arabic - 500000 >= 0){
 	roman += "d";
 	arabic -= 500000;
 	}
-	while (arabic - 400000 >= 0){
+	if (arabic - 400000 >= 0){
 	roman += "cd";
 	arabic -= 400000;
 	}
@@ -1428,15 +1428,15 @@ const QString arabicToRoman(uint i)
 	roman += "c";
 	arabic -= 100000;
 	}
-	while (arabic - 90000 >= 0){
+	if (arabic - 90000 >= 0){
 	roman += "xc";
 	arabic -= 90000;
 	}
-	while (arabic - 50000 >= 0){
+	if (arabic - 50000 >= 0){
 	roman += "l";
 	arabic -= 50000;
 	}
-	while (arabic - 40000 >= 0){
+	if (arabic - 40000 >= 0){
 	roman += "xl";
 	arabic -= 40000;
 	}
@@ -1444,15 +1444,15 @@ const QString arabicToRoman(uint i)
 	roman += "x";
 	arabic -= 10000;
 	}
-	while (arabic - 9000 >= 0){
+	if (arabic - 9000 >= 0){
 	roman += "Mx";
 	arabic -= 9000;
 	}
-	while (arabic - 5000 >= 0){
+	if (arabic - 5000 >= 0){
 	roman += "v";
 	arabic -= 5000;
 	}
-	while (arabic - 4000 >= 0){
+	if (arabic - 4000 >= 0){
 	roman += "Mv";
 	arabic -= 4000;
 	}
@@ -1460,15 +1460,15 @@ const QString arabicToRoman(uint i)
 	roman += "M";
 	arabic -= 1000;
 	}
-	while (arabic - 900 >= 0){
+	if (arabic - 900 >= 0){
 	roman += "CM";
 	arabic -= 900;
 	}
-	while (arabic - 500 >= 0){
+	if (arabic - 500 >= 0){
 	roman += "D";
 	arabic -= 500;
 	}
-	while (arabic - 400 >= 0){
+	if (arabic - 400 >= 0){
 	roman += "CD";
 	arabic -= 400;
 	}
@@ -1476,15 +1476,15 @@ const QString arabicToRoman(uint i)
 	roman += "C";
 	arabic -= 100;
 	}
-	while (arabic - 90 >= 0){
+	if (arabic - 90 >= 0){
 	roman += "XC";
 	arabic -= 90;
 	}
-	while (arabic - 50 >= 0){
+	if (arabic - 50 >= 0){
 	roman += "L";
 	arabic -= 50;
 	}
-	while (arabic - 40 >= 0){
+	if (arabic - 40 >= 0){
 	roman += "XL";
 	arabic -= 40;
 	}
@@ -1492,15 +1492,15 @@ const QString arabicToRoman(uint i)
 	roman += "X";
 	arabic -= 10;
 	}
-	while (arabic - 9 >= 0){
+	if (arabic - 9 >= 0){
 	roman += "IX";
 	arabic -= 9;
 	}
-	while (arabic - 5 >= 0){
+	if (arabic - 5 >= 0){
 	roman += "V";
 	arabic -= 5;
 	}
-	while (arabic - 4 >= 0){
+	if (arabic - 4 >= 0){
 	roman += "IV";
 	arabic -= 4;
 	}
