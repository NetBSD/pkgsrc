$NetBSD: patch-src_mkfuns.c,v 1.1 2016/01/17 15:14:47 joerg Exp $

--- src/mkfuns.c.orig	2016-01-16 13:51:04.000000000 +0000
+++ src/mkfuns.c
@@ -1,10 +1,11 @@
 
 /* This is a preprocessor for iLisp3.x sources */
 
+#include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 
-main(int np,char **p)
+int main(int np,char **p)
 {
   char s[500];
   FILE *fo;
