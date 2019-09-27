$NetBSD: patch-core_fpu.c,v 1.1 2019/09/27 15:52:12 hauke Exp $

Declare type of function parameter, or it will default to int...

--- core/fpu.c.orig	2015-09-14 02:11:18.000000000 +0000
+++ core/fpu.c
@@ -814,7 +814,7 @@ float128 _from_native(double n)
 #define _native_log2(a) (log(a) / log(2.0)) /* or log2() */
 #define _native_log(a) log(a)
 #define _native_log1p(a) log((a) + 1.0) /* or log1p() */
-double  _native_tentox(a) {
+double  _native_tentox(double a) {
     /*
      * This is a dumb workaround for a clang bug on OS X 10.10
      * Clang wants to optimize pow(10.0, a) to __exp(a), but
