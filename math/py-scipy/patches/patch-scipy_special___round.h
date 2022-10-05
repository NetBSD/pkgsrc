$NetBSD: patch-scipy_special___round.h,v 1.4 2022/10/05 20:54:31 adam Exp $

SunOS fix
https://github.com/scipy/scipy/issues/9214

--- scipy/special/_round.h.orig	2018-05-05 17:10:11.000000000 +0000
+++ scipy/special/_round.h
@@ -9,6 +9,10 @@
 #include "_c99compat.h"
 #include "cephes/dd_idefs.h"
 
+#if defined(__cplusplus)
+using std::isinf;
+using std::isnan;
+#endif
 
 double add_round_up(double a, double b)
 {
