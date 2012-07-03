$NetBSD: patch-main.c,v 1.1 2012/07/03 18:13:26 joerg Exp $

--- main.c.orig	2012-07-03 10:49:15.000000000 +0000
+++ main.c
@@ -17,7 +17,13 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <setjmp.h>
+#include <string.h>
+#include <unistd.h>
+
+void emitopen(char *, char *, char *);
+emitaddr(unsigned long );
 
 extern int lineno;
 extern int pass,fatal;
