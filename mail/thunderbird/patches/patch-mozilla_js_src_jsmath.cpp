$NetBSD: patch-mozilla_js_src_jsmath.cpp,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/js/src/jsmath.cpp.orig	2013-10-23 22:09:02.000000000 +0000
+++ mozilla/js/src/jsmath.cpp
@@ -244,7 +244,7 @@ js::ecmaAtan2(double y, double x)
     }
 #endif
 
-#if defined(SOLARIS) && defined(__GNUC__)
+#if defined(notSOLARIS) && defined(__GNUC__)
     if (y == 0) {
         if (IsNegativeZero(x))
             return js_copysign(M_PI, y);
