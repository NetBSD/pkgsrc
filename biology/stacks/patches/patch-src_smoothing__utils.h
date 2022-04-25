$NetBSD: patch-src_smoothing__utils.h,v 1.1 2022/04/25 14:34:06 tnn Exp $

avoid ambiguous math functions

--- src/smoothing_utils.h.orig	2020-06-24 17:47:55.000000000 +0000
+++ src/smoothing_utils.h
@@ -24,6 +24,8 @@
 #include <cmath>
 #include <vector>
 
+using std::pow;
+
 extern double sigma;
 
 inline
