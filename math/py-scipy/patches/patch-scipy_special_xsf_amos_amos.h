$NetBSD: patch-scipy_special_xsf_amos_amos.h,v 1.2 2025/02/19 09:23:15 adam Exp $

Prefer C++ headers.
Fix error: 'isinf' was not declared in this scope; did you mean 'std::isinf'?

--- scipy/special/xsf/amos/amos.h.orig	2025-02-16 22:01:46.000000000 +0000
+++ scipy/special/xsf/amos/amos.h
@@ -94,10 +94,13 @@
 
 #include <stdlib.h>
 
-#include <math.h>
-#include <complex.h>
+#include <cmath>
+#include <complex>
 #include <memory>     // unique_ptr
 
+using std::isinf;
+using std::isnan;
+
 namespace xsf {
 namespace amos {
 
