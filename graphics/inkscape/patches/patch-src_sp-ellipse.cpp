$NetBSD: patch-src_sp-ellipse.cpp,v 1.1 2018/06/28 11:18:59 jperkin Exp $

Avoid ambiguous function calls.

--- src/sp-ellipse.cpp.orig	2017-08-06 20:44:00.000000000 +0000
+++ src/sp-ellipse.cpp
@@ -37,6 +37,8 @@
 
 #define SP_2PI (2 * M_PI)
 
+using std::sqrt;
+
 SPGenericEllipse::SPGenericEllipse()
     : SPShape()
     , start(0)
