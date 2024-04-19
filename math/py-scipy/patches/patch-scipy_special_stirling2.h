$NetBSD: patch-scipy_special_stirling2.h,v 1.1 2024/04/19 19:24:25 adam Exp $

Prefer C++ headers.
Fix error: 'isinf' was not declared in this scope; did you mean 'std::isinf'?

--- scipy/special/stirling2.h.orig	2024-04-02 18:31:54.000000000 +0000
+++ scipy/special/stirling2.h
@@ -1,12 +1,15 @@
 #ifndef STIRLING_H
 #define STIRLING_H
 
-#include <complex.h>
-#include <math.h>
+#include <complex>
+#include <cmath>
 #include <stdio.h>
 #include <stdint.h>
 #include <stdlib.h>
 
+using std::isinf;
+using std::isnan;
+
 #include "special/lambertw.h"
 
 
