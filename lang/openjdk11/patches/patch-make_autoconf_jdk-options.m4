$NetBSD: patch-make_autoconf_jdk-options.m4,v 1.1 2019/10/01 12:36:34 tnn Exp $

Silence shell compatibility warnings.

--- make/autoconf/jdk-options.m4.orig	2019-09-19 12:22:38.000000000 +0000
+++ make/autoconf/jdk-options.m4
@@ -207,7 +207,7 @@ AC_DEFUN_ONCE([JDKOPT_SETUP_JDK_OPTIONS]
   AC_ARG_WITH(cacerts-file, [AS_HELP_STRING([--with-cacerts-file],
       [specify alternative cacerts file])])
   AC_MSG_CHECKING([for cacerts file])
-  if test "x$with_cacerts_file" == x; then
+  if test "x$with_cacerts_file" = x; then
     AC_MSG_RESULT([default])
   else
     CACERTS_FILE=$with_cacerts_file
