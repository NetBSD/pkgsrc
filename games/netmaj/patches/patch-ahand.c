$NetBSD: patch-ahand.c,v 1.1 2013/02/26 10:29:34 joerg Exp $

--- ahand.c.orig	2013-02-25 20:41:22.000000000 +0000
+++ ahand.c
@@ -25,6 +25,8 @@
 #include "ahand.h"
 #include "global.h"
 
+static void ah_result_add(ahand_t *a);
+
 extern FILE *df;
 
 ahand_t result_ahand[MAX_RESULT];
@@ -111,7 +113,7 @@ ah_sort(a) ahand_t *a; {
 }
 
 
-ah_result_add(a) ahand_t *a; {
+static void ah_result_add(ahand_t *a) {
 	int i;
 	int rest;
 	int v2=0;
@@ -303,7 +305,7 @@ ah_analize(a,from) ahand_t *a; {
 	if(!found) ah_result_add(a);
 }
 
-ah_print(a,name) ahand_t *a; char *name; {
+void ah_print(ahand_t *a, char *name) {
 	int i,j,n;
 
 	if (!df) return;
