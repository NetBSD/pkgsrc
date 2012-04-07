$NetBSD: patch-lib_isnan.c,v 1.2 2012/04/07 15:14:04 schwarz Exp $

--- lib/isnan.c.orig	2011-04-16 21:08:41.000000000 +0200
+++ lib/isnan.c	2012-04-06 16:16:04.995001524 +0200
@@ -118,7 +118,8 @@
   /* Be careful to not do any floating-point operation on x, such as x == x,
      because x may be a signaling NaN.  */
 #  if defined __TINYC__ || defined __SUNPRO_C || defined __DECC \
-      || (defined __sgi && !defined __GNUC__) || defined __ICC
+      || (defined __sgi && !defined __GNUC__) || defined __ICC \
+      || defined __vax__
   /* The Sun C 5.0, Intel ICC 10.0, and Compaq (ex-DEC) 6.4 compilers don't
      recognize the initializers as constant expressions.  The latter compiler
      also fails when constant-folding 0.0 / 0.0 even when constant-folding is
