$NetBSD: patch-js_src_jsmath.cpp,v 1.1 2016/05/20 18:45:22 youri Exp $

Fix build on SunOS

--- js/src/jsmath.cpp.orig	2013-02-11 22:33:22.000000000 +0000
+++ js/src/jsmath.cpp
@@ -196,7 +196,7 @@ math_atan2_kernel(double x, double y)
 
 #if defined(SOLARIS) && defined(__GNUC__)
     if (x == 0) {
-        if (MOZ_DOUBLE_IS_NEGZERO(y))
+        if (MOZ_DOUBLE_IS_NEGATIVE_ZERO(y))
             return js_copysign(M_PI, x);
         if (y == 0)
             return x;
