$NetBSD: patch-src_Imath_ImathFun.cpp,v 1.1 2024/01/28 12:55:22 wiz Exp $

src/Imath/ImathFun.cpp: In function 'float Imath_3_1::succf(float)':     
src/Imath/ImathFun.cpp:13:12: error: 'isfinite' was not declared in this scope; did you mean 'std::isfinite'?                                                                            
   13 |     return isfinite(f) ?                                                                               
      |            ^~~~~~~~                                                                                    
      |            std::isfinite                                                                               

--- src/Imath/ImathFun.cpp.orig	2024-01-28 12:53:28.995862273 +0000
+++ src/Imath/ImathFun.cpp
@@ -10,25 +10,25 @@ IMATH_INTERNAL_NAMESPACE_SOURCE_ENTER
 
 float succf(float f) IMATH_NOEXCEPT
 {
-    return isfinite(f) ?
+    return std::isfinite(f) ?
             std::nextafter(f, std::numeric_limits<float>::infinity()) : f;
 }
 
 float predf(float f) IMATH_NOEXCEPT
 {
-    return isfinite(f) ?
+    return std::isfinite(f) ?
             std::nextafter(f, -std::numeric_limits<float>::infinity()) : f;
 }
 
 double succd(double d) IMATH_NOEXCEPT
 {
-    return isfinite(d) ?
+    return std::isfinite(d) ?
             std::nextafter(d, std::numeric_limits<double>::infinity()) : d;
 }
 
 double predd(double d) IMATH_NOEXCEPT
 {
-    return isfinite(d) ?
+    return std::isfinite(d) ?
             std::nextafter(d, -std::numeric_limits<double>::infinity()) : d;
 }
 
