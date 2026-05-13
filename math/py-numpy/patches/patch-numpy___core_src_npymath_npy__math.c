$NetBSD: patch-numpy___core_src_npymath_npy__math.c,v 1.1 2026/05/13 02:10:58 riastradh Exp $

Workaround for https://github.com/numpy/numpy/issues/23379
ImportError: /home/riastradh/pkgsrc/current/pkg/lib/python3.11/site-packages/numpy/linalg/_umath_linalg.so: Undefined PLT symbol "log1pl" (symnum = 20)

--- numpy/_core/src/npymath/npy_math.c.orig	2026-03-28 23:41:33.000000000 +0000
+++ numpy/_core/src/npymath/npy_math.c
@@ -7,3 +7,20 @@
 
 #define NPY_INLINE_MATH 0
 #include "npy_math_internal.h"
+
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if __NetBSD_Version__ < 1000000000
+/* hack for missing log2l() symbol - see https://github.com/numpy/numpy/issues/23379 */
+/* in this file because it's included by all _multiarray_* so files */
+long double log2l(long double arg) {
+    return log2(arg);
+}
+long double log1pl(long double arg) {
+    return log1p(arg);
+}
+long double expm1l(long double arg) {
+    return expm1(arg);
+}
+#endif
+#endif
