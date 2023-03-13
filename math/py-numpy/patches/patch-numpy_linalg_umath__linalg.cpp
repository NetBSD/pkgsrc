$NetBSD: patch-numpy_linalg_umath__linalg.cpp,v 1.1 2023/03/13 21:11:15 wiz Exp $

Workaround for https://github.com/numpy/numpy/issues/23379

--- numpy/linalg/umath_linalg.cpp.orig	2023-02-05 17:13:47.689365400 +0000
+++ numpy/linalg/umath_linalg.cpp
@@ -4567,3 +4567,16 @@ PyMODINIT_FUNC PyInit__umath_linalg(void
 
     return m;
 }
+
+#ifdef __NetBSD__
+/* hack for missing log2l() symbol - see https://github.com/numpy/numpy/issues/23379 */
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
