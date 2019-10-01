$NetBSD: patch-make_autoconf_lib-x11.m4,v 1.1 2019/10/01 12:36:34 tnn Exp $

Add rpath for X11.

--- make/autoconf/lib-x11.m4.orig	2019-09-19 12:22:38.000000000 +0000
+++ make/autoconf/lib-x11.m4
@@ -95,6 +95,8 @@ AC_DEFUN_ONCE([LIB_SETUP_X11],
           -R$OPENWIN_HOME/lib$OPENJDK_TARGET_CPU_ISADIR"
     fi
 
+    X_LIBS="@COMPILER_RPATH_FLAG@${x_libraries} ${X_LIBS}"
+
     AC_LANG_PUSH(C)
     OLD_CFLAGS="$CFLAGS"
     CFLAGS="$CFLAGS $SYSROOT_CFLAGS $X_CFLAGS"
