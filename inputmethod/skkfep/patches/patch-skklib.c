$NetBSD: patch-skklib.c,v 1.1 2012/12/20 21:50:47 joerg Exp $

--- skklib.c.orig	2012-12-20 14:41:31.000000000 +0000
+++ skklib.c
@@ -15,6 +15,8 @@ static char *allocStr();
 /* char *malloc(); */
 int hashVal();
 
+static void mergeDictionary(Dictionary dic, char *dicname);
+
 /*
  * Open SKK
  */
@@ -235,9 +237,7 @@ int okuri;
 	return citem0;
 }
 
-closeSKK(dic,dicname)
-Dictionary dic;
-char *dicname;
+void closeSKK(Dictionary dic, char *dicname)
 {
 	char *buf;
 	FILE *f;
@@ -301,9 +301,7 @@ char *dicname;
 
 /* #define DEBUG_MERGE /* debug dictionary merge */
 
-mergeDictionary(dic,dicname)
-Dictionary dic;
-char *dicname;
+static void mergeDictionary(Dictionary dic, char *dicname)
 {
 	FILE *f;
 	CandList cand,dcand;
