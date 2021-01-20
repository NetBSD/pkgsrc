$NetBSD: patch-m4_gettext.m4,v 1.1 2021/01/20 03:09:03 brook Exp $

mkinstalldirs is no longer used.

--- m4/gettext.m4.orig	2005-04-25 20:28:35.000000000 +0000
+++ m4/gettext.m4
@@ -359,7 +359,6 @@ dnl            USE_INCLUDED_LIBINTL, BUI
 AC_DEFUN([AM_INTL_SUBDIR],
 [
   AC_REQUIRE([AC_PROG_INSTALL])dnl
-  AC_REQUIRE([AM_MKINSTALLDIRS])dnl
   AC_REQUIRE([AC_PROG_CC])dnl
   AC_REQUIRE([AC_CANONICAL_HOST])dnl
   AC_REQUIRE([gt_GLIBC2])dnl
