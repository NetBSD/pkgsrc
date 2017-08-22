$NetBSD: patch-scipy_special___round.h,v 1.1 2017/08/22 21:37:27 he Exp $

This conditional is just wrong, when built with c++, __STDC_VERSION__
is not defined.  Make a cheezy fix which insists on <fenv.h> when
built with C++.

--- scipy/special/_round.h.orig	2017-01-09 07:17:38.000000000 +0000
+++ scipy/special/_round.h
@@ -49,7 +49,7 @@ double add_round_down(double a, double b
 
 
 /* Helper code for testing _round.h. */
-#if __STDC_VERSION__ >= 199901L
+#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__cplusplus)
 /* We have C99 */
 #include <fenv.h>
 #else
