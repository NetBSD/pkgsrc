$NetBSD: patch-src_hyperloglog.c,v 1.3 2025/05/22 18:44:41 adam Exp $

Fix the case of the missing llroundl on NetBSD. Patch by Matthias Petermann.

--- src/hyperloglog.c.orig	2025-05-13 13:28:36.000000000 +0000
+++ src/hyperloglog.c
@@ -26,6 +26,16 @@
 #include <immintrin.h>
 #endif
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if __NetBSD_Version__ < 799007200
+/* llroundl not present in NetBSD libm before 7.99.71 */
+long long int llroundl (long double x) {
+    return (long long int) roundl (x);
+}
+#endif
+#endif
+
 /* The Redis HyperLogLog implementation is based on the following ideas:
  *
  * * The use of a 64 bit hash function as proposed in [1], in order to estimate
