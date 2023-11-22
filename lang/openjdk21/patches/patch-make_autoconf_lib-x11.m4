$NetBSD: patch-make_autoconf_lib-x11.m4,v 1.1 2023/11/22 14:06:50 ryoon Exp $

Add rpath for X11.

--- make/autoconf/lib-x11.m4.orig	2022-02-05 03:44:09.000000000 +0000
+++ make/autoconf/lib-x11.m4
@@ -92,6 +92,8 @@ AC_DEFUN_ONCE([LIB_SETUP_X11],
       AC_MSG_ERROR([Could not find X11 libraries. $HELP_MSG])
     fi
 
+    X_LIBS="@COMPILER_RPATH_FLAG@${x_libraries} ${X_LIBS}"
+
     AC_LANG_PUSH(C)
     OLD_CFLAGS="$CFLAGS"
     CFLAGS="$CFLAGS $SYSROOT_CFLAGS $X_CFLAGS"
