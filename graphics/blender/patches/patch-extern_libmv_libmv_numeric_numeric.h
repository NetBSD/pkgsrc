$NetBSD: patch-extern_libmv_libmv_numeric_numeric.h,v 1.2 2013/10/12 22:11:00 ryoon Exp $

--- extern/libmv/libmv/numeric/numeric.h.orig	2013-04-05 09:23:20.000000000 +0000
+++ extern/libmv/libmv/numeric/numeric.h
@@ -33,7 +33,7 @@
 #include <Eigen/QR>
 #include <Eigen/SVD>
 
-#if (defined(_WIN32) || defined(__APPLE__) || defined(__FreeBSD__)) && !defined(__MINGW64__)
+#if (defined(_WIN32) || defined(__APPLE__) || defined(__FreeBSD__)  || defined(__NetBSD__)) && !defined(__MINGW64__)
   static void sincos(double x, double *sinx, double *cosx) {
     *sinx = sin(x);
     *cosx = cos(x);
