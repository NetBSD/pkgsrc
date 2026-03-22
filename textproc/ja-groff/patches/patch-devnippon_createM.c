$NetBSD: patch-devnippon_createM.c,v 1.1 2026/03/22 10:34:03 nia Exp $

Recent GCC no longer likes implicit anything.

--- devnippon/createM.c.orig	2026-03-22 10:13:45.618635476 +0000
+++ devnippon/createM.c
@@ -1,4 +1,6 @@
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 #define WCTABLE_OFFSET 0xa1
 #define WCTABLE_SIZE 94
@@ -7,7 +9,7 @@
 #  define BUFSIZ 1024
 #endif
 
-
+int
 main(argc, argv)
 int argc;
 char *argv[];
