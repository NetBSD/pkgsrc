$NetBSD: patch-scipy_special_sf__error.c,v 1.1 2023/05/05 14:59:25 adam Exp $

Workaround for https://github.com/numpy/numpy/issues/23379
Add hack here, because sf_error.c is compiled in both _ufuncs.so and _ufuncs_cxx.so.

--- scipy/special/sf_error.c.orig	2023-05-05 14:40:42.972802223 +0000
+++ scipy/special/sf_error.c
@@ -5,6 +5,18 @@
 
 #include "sf_error.h"
 
+#ifdef __NetBSD__
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
+
 const char *sf_error_messages[] = {
     "no error",
     "singularity",
