$NetBSD: patch-yearcal.c,v 1.1 2026/03/17 14:58:31 nia Exp $

ANSIfy.

--- yearcal.c.orig	2026-03-17 14:45:52.086768142 +0000
+++ yearcal.c
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <stdlib.h>
 #include "caldate.h"
 
 char *montab[] = {
@@ -16,9 +17,7 @@ char *montab[] = {
 , "December"
 } ;
 
-void main(argc,argv)
-int argc;
-char **argv;
+int main(int argc, char **argv)
 {
   int year;
   long daystart;
