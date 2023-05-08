$NetBSD: patch-scipy_special_Faddeeva.hh,v 1.1 2023/05/08 20:39:18 tnn Exp $

Fix missing isnan/isinf.

--- scipy/special/Faddeeva.hh.orig	1970-01-01 00:00:00.000000000 +0000
+++ scipy/special/Faddeeva.hh
@@ -28,6 +28,8 @@
 #define FADDEEVA_HH 1
 
 #include <complex>
+using std::isinf;
+using std::isnan;
 
 namespace Faddeeva {
 
