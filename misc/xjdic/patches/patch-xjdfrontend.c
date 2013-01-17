$NetBSD: patch-xjdfrontend.c,v 1.1 2013/01/17 16:00:02 joerg Exp $

--- xjdfrontend.c.orig	2013-01-16 14:01:40.000000000 +0000
+++ xjdfrontend.c
@@ -2917,10 +2917,7 @@ void FiltSet()
 
 /*                  M A I N                                      */
 
-main(argc,argv)
-int argc;
-unsigned char **argv;
-
+main(int argc, char **argv)
 {
 	int i,j,ip,cmdmode,bit8,escf;
   	unsigned char *dicenv,strtmp[50];
