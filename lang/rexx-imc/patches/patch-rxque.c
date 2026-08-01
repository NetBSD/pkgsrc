$NetBSD: patch-rxque.c,v 1.1 2026/08/01 18:11:29 ryoon Exp $

--- rxque.c.orig	1999-01-17 23:00:13.000000000 +0000
+++ rxque.c
@@ -5,6 +5,7 @@
 #include<errno.h>
 #include<signal.h>
 #include<fcntl.h>
+#include<string.h>
 #include<sys/time.h>
 #include<sys/types.h>
 #include<unistd.h>
@@ -30,7 +31,7 @@ unsigned max;                        /* Number of stac
 int empty;                           /* Is stack empty when first==last? */
 unsigned max;                        /* Number of stack elements allocated */
 
-main(argc,argv)           /* Specify "-csh" and/or a filename */
+int main(argc,argv)           /* Specify "-csh" and/or a filename */
 int argc;
 char **argv;
 {
