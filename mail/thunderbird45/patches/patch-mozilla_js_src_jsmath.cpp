$NetBSD: patch-mozilla_js_src_jsmath.cpp,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/js/src/jsmath.cpp.orig	2016-04-07 21:33:24.000000000 +0000
+++ mozilla/js/src/jsmath.cpp
@@ -272,7 +272,7 @@ js::ecmaAtan2(double y, double x)
     }
 #endif
 
-#if defined(SOLARIS) && defined(__GNUC__)
+#if defined(notSOLARIS) && defined(__GNUC__)
     if (y == 0) {
         if (IsNegativeZero(x))
             return js_copysign(M_PI, y);
