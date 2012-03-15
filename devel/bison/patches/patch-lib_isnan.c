$NetBSD: patch-lib_isnan.c,v 1.1 2012/03/15 07:50:22 jklos Exp $

--- lib/isnan.c.orig	2011-04-16 19:08:41.000000000 +0000
+++ lib/isnan.c
@@ -119,6 +119,7 @@ FUNC (DOUBLE x)
      because x may be a signaling NaN.  */
 #  if defined __TINYC__ || defined __SUNPRO_C || defined __DECC \
       || (defined __sgi && !defined __GNUC__) || defined __ICC
+      || defined __vax__
   /* The Sun C 5.0, Intel ICC 10.0, and Compaq (ex-DEC) 6.4 compilers don't
      recognize the initializers as constant expressions.  The latter compiler
      also fails when constant-folding 0.0 / 0.0 even when constant-folding is
