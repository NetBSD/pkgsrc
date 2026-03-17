$NetBSD: patch-easter.c,v 1.1 2026/03/17 14:58:30 nia Exp $

ANSIfy.

--- easter.c.orig	2026-03-17 14:48:43.284644903 +0000
+++ easter.c
@@ -1,13 +1,13 @@
 #include <stdio.h>
+#include <stdlib.h>
 #include "caldate.h"
 
 char *dayname[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" } ;
 
 char out[101];
 
-main(argc,argv)
-int argc;
-char **argv;
+int
+main(int argc, char **argv)
 {
   struct caldate cd;
   long day;
