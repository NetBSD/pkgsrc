$NetBSD: patch-src_examples_formula.cpp,v 1.1 2013/06/26 15:49:31 joerg Exp $

--- src/examples/formula.cpp.orig	2013-06-20 19:27:22.000000000 +0000
+++ src/examples/formula.cpp
@@ -60,7 +60,7 @@ int little_main(user_interaction & ui, S
     else
     {
 	string formula = crit_action_canonize_string(argv[1]);
-	deci tmp = calculus(formula);
+	libdar::deci tmp = calculus(formula);
 
 	cout << tmp.human() << endl;
 
@@ -113,7 +113,7 @@ static infinint calculus(const string & 
 	return calculus(string(formula.begin() + 1, formula.end() - 1));
     else  // assuming an integer
     {
-	deci tmp = formula;
+	libdar::deci tmp = formula;
 	return tmp.computer();
     }
 }
