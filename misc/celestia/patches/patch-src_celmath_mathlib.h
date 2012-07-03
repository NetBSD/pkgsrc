$NetBSD: patch-src_celmath_mathlib.h,v 1.2 2012/07/03 17:40:36 joerg Exp $

--- src/celmath/mathlib.h.orig	2002-03-12 04:58:25.000000000 +0000
+++ src/celmath/mathlib.h
@@ -11,7 +11,7 @@
 #define _MATHLIB_H_
 
 #include <cmath>
-#include <stdlib.h>
+#include <cstdlib>
 
 #define PI 3.14159265358979323846
 
