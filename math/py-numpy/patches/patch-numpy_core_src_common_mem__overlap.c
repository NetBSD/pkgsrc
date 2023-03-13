$NetBSD: patch-numpy_core_src_common_mem__overlap.c,v 1.1 2023/03/13 21:11:15 wiz Exp $

Workaround for https://github.com/numpy/numpy/issues/23379

--- numpy/core/src/common/mem_overlap.c.orig	2023-02-05 17:13:47.573364500 +0000
+++ numpy/core/src/common/mem_overlap.c
@@ -921,3 +921,17 @@ solve_may_have_internal_overlap(PyArrayO
     /* Solve */
     return solve_diophantine(nterms, terms, -1, max_work, 1, x);
 }
+
+#ifdef __NetBSD__
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
