$NetBSD: patch-isnan.c,v 1.1 2013/10/29 17:34:04 jklos Exp $

--- lib/isnan.c.orig	2013-09-22 06:15:20.000000000 +0000
+++ lib/isnan.c
@@ -118,7 +118,7 @@ FUNC (DOUBLE x)
   /* Be careful to not do any floating-point operation on x, such as x == x,
      because x may be a signaling NaN.  */
 #  if defined __SUNPRO_C || defined __ICC || defined _MSC_VER \
-      || defined __DECC || defined __TINYC__ \
+      || defined __DECC || defined __TINYC__ || defined __vax__ \
       || (defined __sgi && !defined __GNUC__)
   /* The Sun C 5.0, Intel ICC 10.0, Microsoft Visual C/C++ 9.0, Compaq (ex-DEC)
      6.4, and TinyCC compilers don't recognize the initializers as constant
