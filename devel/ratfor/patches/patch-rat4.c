$NetBSD: patch-rat4.c,v 1.1 2012/11/01 19:49:32 joerg Exp $

--- rat4.c.orig	2012-10-30 19:09:58.000000000 +0000
+++ rat4.c
@@ -68,6 +68,13 @@ Compile Level
 #include "ratdef.h"
 #include "ratcom.h"
 
+void balpar(void);
+void brknxt(int sp, int lextyp[], int labval[], int token);
+void forcod(int *lab);
+void outcon(int n);
+void outgo(int n);
+void cascod (int lab, int token);
+
 /* keywords: */
 
 char sdo[3] = {
@@ -363,7 +370,7 @@ S_CHAR str[];
  * balpar - copy balanced paren string
  *
  */
-balpar()
+void balpar(void)
 {
 	S_CHAR token[MAXTOK];
 	int t,nlpar;
@@ -1009,11 +1016,7 @@ S_CHAR c;
 /*
  * brknxt - generate code for break n and next n; n = 1 is default
  */
-brknxt(sp, lextyp, labval, token)
-int sp;
-int lextyp[];
-int labval[];
-int token;
+void brknxt(int sp, int lextyp[], int labval[], int token)
 {
 	int i, n;
 	S_CHAR t, ptoken[MAXTOK];
@@ -1099,8 +1102,7 @@ int lab;
  * forcod - beginning of for statement
  *
  */
-forcod(lab)
-int *lab;
+void forcod(int *lab)
 {
 	S_CHAR t, token[MAXTOK];
 	int i, j, nlpar,tlab;
@@ -1331,8 +1333,7 @@ S_CHAR c;
  * outcon - output "n   continue"
  *
  */
-outcon(n)
-int n;
+void outcon(int n)
 {
 	xfer = NO;
 	if (n <= 0 && outp == 0)
@@ -1404,8 +1405,7 @@ FILE * fd;
  * outgo - output "goto  n"
  *
  */
-outgo(n)
-int n;
+void outgo(int n)
 {
 	if (xfer == YES)
 		return;
@@ -1864,9 +1864,7 @@ int size;
  * cascod - generate code for case or default label
  *
  */
-cascod (lab, token)
-int lab;
-int token;
+void cascod (int lab, int token)
 {
 	int t, l, lb, ub, i, j, junk;
 	S_CHAR scrtok[MAXTOK];
