$NetBSD: patch-scipy_special_xsf_amos_amos.h,v 1.1 2025/01/05 08:58:47 adam Exp $

Prefer C++ headers.
Fix error: 'isinf' was not declared in this scope; did you mean 'std::isinf'?

--- scipy/special/xsf/amos/amos.h.orig	2025-01-02 22:53:29.000000000 +0000
+++ scipy/special/xsf/amos/amos.h
@@ -94,8 +94,11 @@
 
 #include <stdlib.h>
 
-#include <math.h>
-#include <complex.h>
+#include <cmath>
+#include <complex>
+
+using std::isinf;
+using std::isnan;
 
 namespace xsf {
 namespace amos {
