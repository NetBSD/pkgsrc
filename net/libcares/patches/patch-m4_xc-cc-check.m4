$NetBSD: patch-m4_xc-cc-check.m4,v 1.1 2017/07/15 17:15:17 wiz Exp $

Do not prescribe what should be in CFLAGS/CPPFLAGS.

--- m4/xc-cc-check.m4.orig	2016-01-23 22:41:55.000000000 +0000
+++ m4/xc-cc-check.m4
@@ -59,7 +59,6 @@ dnl Private macro.
 
 AC_DEFUN([_XC_PROG_CC], [
   AC_REQUIRE([_XC_PROG_CC_PREAMBLE])dnl
-  AC_REQUIRE([XC_CHECK_USER_FLAGS])dnl
   AC_REQUIRE([AC_PROG_INSTALL])dnl
   AC_REQUIRE([AC_PROG_CC])dnl
   AC_REQUIRE([AM_PROG_CC_C_O])dnl
