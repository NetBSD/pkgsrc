$NetBSD: patch-config_override.m4,v 1.1 2021/07/25 15:06:25 js Exp $

Allow using newer autoconf versions. 2.71 works just fine.

--- config/override.m4.orig	2020-07-23 06:35:16.916379838 +0000
+++ config/override.m4
@@ -38,11 +38,7 @@ dnl   m4_define([_GCC_AUTOCONF_VERSION],
 dnl in configure.ac before AC_INIT,
 dnl without rewriting this file.
 dnl Or for updating the whole tree at once with the definition above.
-AC_DEFUN([_GCC_AUTOCONF_VERSION_CHECK],
-[m4_if(m4_defn([_GCC_AUTOCONF_VERSION]),
-  m4_defn([m4_PACKAGE_VERSION]), [],
-  [m4_fatal([Please use exactly Autoconf ]_GCC_AUTOCONF_VERSION[ instead of ]m4_defn([m4_PACKAGE_VERSION])[.])])
-])
+AC_DEFUN([_GCC_AUTOCONF_VERSION_CHECK], [])
 m4_define([AC_INIT], m4_defn([AC_INIT])[
 _GCC_AUTOCONF_VERSION_CHECK
 ])
