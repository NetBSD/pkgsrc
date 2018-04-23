$NetBSD: patch-src_hyperloglog.c,v 1.1 2018/04/23 14:57:57 fhajny Exp $

Fix the case of the missing llroundl on NetBSD. Patch by Matthias Petermann.

--- src/hyperloglog.c.orig	2018-03-26 16:04:15.000000000 +0000
+++ src/hyperloglog.c
@@ -34,6 +34,16 @@
 #include <stdint.h>
 #include <math.h>
 
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
  * * The use of a 64 bit hash function as proposed in [1], in order to don't
