$NetBSD: patch-scipy_special_special_amos_amos.h,v 1.1 2024/04/19 19:24:25 adam Exp $

Prefer C++ headers.
Fix error: 'isinf' was not declared in this scope; did you mean 'std::isinf'?

--- scipy/special/special/amos/amos.h.orig	2024-04-19 14:20:53.078767873 +0000
+++ scipy/special/special/amos/amos.h
@@ -93,8 +93,11 @@
 
 #include <stdlib.h>
 
-#include <math.h>
-#include <complex.h>
+#include <cmath>
+#include <complex>
+
+using std::isinf;
+using std::isnan;
 
 static int amos_acai(std::complex<double>, double, int, int, int, std::complex<double> *, double, double, double, double);
 static int amos_acon(std::complex<double>, double, int, int, int, std::complex<double> *, double, double, double, double, double);
