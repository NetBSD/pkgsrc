$NetBSD: patch-scipy_special_wright.hh,v 1.1 2023/05/08 20:39:18 tnn Exp $

Fix missing isnan/isinf.

--- scipy/special/wright.hh.orig	1970-01-01 00:00:00.000000000 +0000
+++ scipy/special/wright.hh
@@ -2,6 +2,8 @@
 #define WRIGHT_HH
 
 #include <complex>
+using std::isinf;
+using std::isnan;
 
 namespace wright {
 
