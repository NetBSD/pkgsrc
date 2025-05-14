$NetBSD: patch-aclocal.m4,v 1.1 2025/05/14 05:24:28 adam Exp $

Pkgsrc doesn't have automake 1.7 yet.

--- aclocal.m4.orig	2025-05-13 20:04:20.812165135 +0000
+++ aclocal.m4
@@ -489,7 +489,7 @@ AC_DEFUN([AM_XGETTEXT_OPTION],
 # generated from the m4 files accompanying Automake X.Y.
 # (This private macro should not be called outside this file.)
 AC_DEFUN([AM_AUTOMAKE_VERSION],
-[am__api_version='1.17'
+[am__api_version='1.16'
 dnl Some users find AM_AUTOMAKE_VERSION and mistake it for a way to
 dnl require some minimum version.  Point them to the right macro.
 m4_if([$1], [1.17], [],
