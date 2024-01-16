$NetBSD: patch-src_liboutils_minmax.h,v 1.1 2024/01/16 14:19:00 vins Exp $

MIN/MAX macros for SunOS

--- src/liboutils/minmax.h.orig	2024-01-16 14:06:20.323098287 +0000
+++ src/liboutils/minmax.h
@@ -0,0 +1,10 @@
+/* MAX(a,b) returns the maximum of A and B.  */
+#ifndef MAX
+# define MAX(a,b) ((a) > (b) ? (a) : (b))
+#endif
+
+/* MIN(a,b) returns the minimum of A and B.  */
+#ifndef MIN
+# define MIN(a,b) ((a) < (b) ? (a) : (b))
+#endif
+
