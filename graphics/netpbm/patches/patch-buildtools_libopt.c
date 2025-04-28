$NetBSD: patch-buildtools_libopt.c,v 1.1 2025/04/28 18:19:27 tnn Exp $

Don't redefine bool.

--- buildtools/libopt.c.orig	2025-04-28 18:14:43.639955093 +0000
+++ buildtools/libopt.c
@@ -88,8 +88,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
-
-typedef unsigned char bool;
+#include <stdbool.h>
 #ifndef TRUE
 #define TRUE (1)
 #endif
