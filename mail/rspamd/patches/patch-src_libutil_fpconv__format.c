$NetBSD: patch-src_libutil_fpconv__format.c,v 1.1 2026/08/11 09:32:02 jperkin Exp $

Support MIN/MAX where unavailable.

--- src/libutil/fpconv_format.c.orig	2026-08-11 09:27:23.638564880 +0000
+++ src/libutil/fpconv_format.c
@@ -17,6 +17,13 @@ static_assert(FPCONV_PRECISION_ALL > 17,
 #define absv(n) ((n) < 0 ? -(n) : (n))
 #define minv(a, b) ((a) < (b) ? (a) : (b))
 
+#ifndef MIN
+#define MIN(a, b)	((a) < (b) ? (a) : (b))
+#endif
+#ifndef MAX
+#define MAX(a, b)	((a) < (b) ? (b) : (a))
+#endif
+
 static inline int
 round_up_digits (char *digits, int ndigits)
 {
