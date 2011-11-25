$NetBSD: patch-src_celmath_mathlib.h,v 1.1 2011/11/25 22:08:30 joerg Exp $

--- src/celmath/mathlib.h.orig	2011-11-25 16:18:13.000000000 +0000
+++ src/celmath/mathlib.h
@@ -11,7 +11,7 @@
 #define _MATHLIB_H_
 
 #include <cmath>
-#include <stdlib.h>
+#include <cstdlib>
 
 #define PI 3.14159265358979323846
 
