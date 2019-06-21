$NetBSD: patch-contrib_fpconv_fpconv.c,v 1.1 2019/06/21 15:02:54 jperkin Exp $

Provide compat MIN/MAX macros.

--- contrib/fpconv/fpconv.c.orig	2019-05-23 14:41:27.000000000 +0000
+++ contrib/fpconv/fpconv.c
@@ -14,6 +14,13 @@
 #define absv(n) ((n) < 0 ? -(n) : (n))
 #define minv(a, b) ((a) < (b) ? (a) : (b))
 
+#ifndef MIN
+#define MIN(a, b)	((a) < (b) ? (a) : (b))
+#endif
+#ifndef MAX
+#define MAX(a, b)	((a) < (b) ? (b) : (a))
+#endif
+
 static uint64_t tens[] = {
 		10000000000000000000U, 1000000000000000000U, 100000000000000000U,
 		10000000000000000U, 1000000000000000U, 100000000000000U,
