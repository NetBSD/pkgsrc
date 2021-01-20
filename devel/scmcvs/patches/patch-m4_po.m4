$NetBSD: patch-m4_po.m4,v 1.1 2021/01/20 03:09:03 brook Exp $

mkinstalldirs is no longer used.

--- m4/po.m4.orig	2005-03-23 00:04:29.000000000 +0000
+++ m4/po.m4
@@ -24,7 +24,6 @@ AC_DEFUN([AM_PO_SUBDIRS],
 [
   AC_REQUIRE([AC_PROG_MAKE_SET])dnl
   AC_REQUIRE([AC_PROG_INSTALL])dnl
-  AC_REQUIRE([AM_MKINSTALLDIRS])dnl
   AC_REQUIRE([AM_NLS])dnl
 
   dnl Perform the following tests also if --disable-nls has been given,
