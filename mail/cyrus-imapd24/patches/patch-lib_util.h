$NetBSD: patch-lib_util.h,v 1.1 2026/03/18 17:06:32 nia Exp $

Fix implicit declaration of ctype functions.

--- lib/util.h.orig	2026-03-18 16:29:15.000971824 +0000
+++ lib/util.h
@@ -52,6 +52,7 @@
 #include <sys/types.h>
 #include <limits.h>
 #include <stdarg.h>
+#include <ctype.h>
 
 #define BIT32_MAX 4294967295U
 
