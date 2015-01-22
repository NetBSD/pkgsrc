$NetBSD: patch-lib_isnan.c,v 1.4 2015/01/22 04:57:57 mef Exp $

Fix definition of NaN on VAX.

--- lib/isnan.c.orig	2012-03-30 07:18:32.000000000 +0000
+++ lib/isnan.c
@@ -119,7 +119,7 @@ FUNC (DOUBLE x)
      because x may be a signaling NaN.  */
 #  if defined __SUNPRO_C || defined __ICC || defined _MSC_VER \
       || defined __DECC || defined __TINYC__ \
-      || (defined __sgi && !defined __GNUC__)
+      || (defined __sgi && !defined __GNUC__) || defined __vax__
   /* The Sun C 5.0, Intel ICC 10.0, Microsoft Visual C/C++ 9.0, Compaq (ex-DEC)
      6.4, and TinyCC compilers don't recognize the initializers as constant
      expressions.  The Compaq compiler also fails when constant-folding
