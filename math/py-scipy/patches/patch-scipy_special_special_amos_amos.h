$NetBSD: patch-scipy_special_special_amos_amos.h,v 1.2 2024/07/31 18:15:38 adam Exp $

Prefer C++ headers.
Fix error: 'isinf' was not declared in this scope; did you mean 'std::isinf'?

--- scipy/special/special/amos/amos.h.orig	2024-06-24 18:58:56.000000000 +0000
+++ scipy/special/special/amos/amos.h
@@ -94,8 +94,11 @@
 
 #include <stdlib.h>
 
-#include <math.h>
-#include <complex.h>
+#include <cmath>
+#include <complex>
+
+using std::isinf;
+using std::isnan;
 
 namespace special {
 namespace amos {
