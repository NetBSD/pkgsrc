$NetBSD: patch-src_celmath_mathlib.h,v 1.3 2013/10/27 21:21:26 dholland Exp $

--- src/celmath/mathlib.h.orig	2011-06-05 16:11:15.000000000 +0000
+++ src/celmath/mathlib.h
@@ -11,7 +11,7 @@
 #define _CELMATH_MATHLIB_H_
 
 #include <cmath>
-#include <stdlib.h>
+#include <cstdlib>
 
 #define PI 3.14159265358979323846
 
