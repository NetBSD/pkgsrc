$NetBSD: patch-scipy_special___round.h,v 1.2 2018/06/14 14:29:16 jperkin Exp $

This conditional is just wrong, when built with c++, __STDC_VERSION__
is not defined.  Make a cheezy fix which insists on <fenv.h> when
built with C++.

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
@@ -49,7 +53,7 @@ double add_round_down(double a, double b
 
 
 /* Helper code for testing _round.h. */
-#if __STDC_VERSION__ >= 199901L
+#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__cplusplus)
 /* We have C99 */
 #include <fenv.h>
 #else
