$NetBSD: patch-unify.c,v 1.1 2025/09/29 20:45:38 mrg Exp $

Fix compilation with GCC 14.

--- unify.c.orig	2022-07-11 18:28:40.000000000 -0700
+++ unify.c	2025-09-25 10:49:58.011813558 -0700
@@ -9,8 +9,8 @@
 */
 
 #include <stdio.h>
-
-extern char *malloc();
+#include <stdlib.h>
+#include <string.h>
 
 #define FIND_NEXT	0
 #define PARSE_UNIDIFF	1
