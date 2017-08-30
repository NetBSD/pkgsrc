$NetBSD: patch-acinclude.m4,v 1.1 2017/08/30 10:35:54 martin Exp $

Remove alpha specific -miee* options currently not working on NetBSD (needs
further investigation)

--- acinclude.m4.orig	2016-09-27 09:58:14.000000000 +0200
+++ acinclude.m4	2017-08-30 12:23:59.333559123 +0200
@@ -102,7 +102,7 @@
   saved_CFLAGS="$CFLAGS"
   AC_CACHE_CHECK([for IEEE-754 switches], mpfr_cv_ieee_switches, [
   if test -n "$GCC"; then
-    mpfr_cv_ieee_switches="-mfp-rounding-mode=d -mieee-with-inexact"
+    mpfr_cv_ieee_switches=""
   else
     mpfr_cv_ieee_switches="-fprm d -ieee_with_inexact"
   fi
