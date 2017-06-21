$NetBSD: patch-acinclude.m4,v 1.1.2.2 2017/06/21 18:26:00 bsiegert Exp $

Fixed memory allocation.

Fixed detection of __attribute__((__mode__(XX))) for sunpro.

--- acinclude.m4.orig	2016-12-17 00:45:27.000000000 +0900
+++ acinclude.m4	2017-06-14 13:05:04.000000000 +0900
@@ -741,7 +741,7 @@ main ()
   long i;
   for (i = 0; i < 88 + 1; i++)
     a[i] = ~0L;
-  r = malloc (10000 * sizeof (unsigned long));
+  r = calloc (10000, sizeof (unsigned long));
   r2 = r;
   for (i = 0; i < 528; i += 23)
     {
@@ -3228,7 +3228,15 @@ dnl  Introduced in gcc 2.2, but perhaps 
 AC_DEFUN([GMP_C_ATTRIBUTE_MODE],
 [AC_CACHE_CHECK([whether gcc __attribute__ ((mode (XX))) works],
                 gmp_cv_c_attribute_mode,
-[AC_TRY_COMPILE([typedef int SItype __attribute__ ((mode (SI)));], ,
+[AC_TRY_COMPILE([
+  typedef int SItype __attribute__ ((mode (SI)));
+  typedef int QItype __attribute__ ((mode (QI)));
+], [
+  switch (1) {
+  case sizeof(SItype):
+  case sizeof(QItype): ;
+  }
+],
   gmp_cv_c_attribute_mode=yes, gmp_cv_c_attribute_mode=no)
 ])
 if test $gmp_cv_c_attribute_mode = yes; then
