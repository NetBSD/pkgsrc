$NetBSD: patch-extern_libmv_libmv_numeric_numeric.h,v 1.1 2012/12/03 13:15:51 ryoon Exp $

--- extern/libmv/libmv/numeric/numeric.h.orig	2012-10-09 18:42:49.000000000 +0000
+++ extern/libmv/libmv/numeric/numeric.h
@@ -33,7 +33,7 @@
 #include <Eigen/QR>
 #include <Eigen/SVD>
 
-#if (defined(_WIN32) || defined(__APPLE__) || defined(__FreeBSD__)) && !defined(__MINGW64__)
+#if (defined(_WIN32) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)) && !defined(__MINGW64__)
   void static sincos (double x, double *sinx, double *cosx) {
     *sinx = sin(x);
     *cosx = cos(x);
