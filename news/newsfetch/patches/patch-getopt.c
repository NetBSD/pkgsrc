$NetBSD: patch-getopt.c,v 1.1 2026/03/22 09:42:59 nia Exp $

Fix implicit declaration of strcmp(3).

--- getopt.c.orig	2026-03-22 09:30:28.527011599 +0000
+++ getopt.c
@@ -1,5 +1,6 @@
 /* getopt.c: local customized getopt module for newsfetch program */
 #include        <stdio.h>
+#include        <string.h>
 
 #define EPR                 fprintf(stderr,
 #define ERR(str, chr)       if(opterr){EPR "%s%c\n", str, chr);}
