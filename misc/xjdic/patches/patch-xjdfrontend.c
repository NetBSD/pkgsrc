$NetBSD: patch-xjdfrontend.c,v 1.2 2013/07/19 12:54:58 joerg Exp $

--- xjdfrontend.c.orig	2013-07-19 10:14:06.000000000 +0000
+++ xjdfrontend.c
@@ -26,6 +26,7 @@
 #include <stdlib.h>
 #include <signal.h>
 #include <errno.h>
+#include <termios.h>
 
 #define HAVE_LOCALE
 #ifdef HAVE_LOCALE
@@ -2917,10 +2918,7 @@ void FiltSet()
 
 /*                  M A I N                                      */
 
-main(argc,argv)
-int argc;
-unsigned char **argv;
-
+main(int argc, char **argv)
 {
 	int i,j,ip,cmdmode,bit8,escf;
   	unsigned char *dicenv,strtmp[50];
