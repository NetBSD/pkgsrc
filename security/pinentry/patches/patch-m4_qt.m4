$NetBSD: patch-m4_qt.m4,v 1.1 2022/01/13 08:05:48 adam Exp $

The "-rpath" option requires an equal sign.

--- m4/qt.m4.orig	2021-08-12 14:30:43.000000000 +0000
+++ m4/qt.m4
@@ -60,7 +60,7 @@ AC_DEFUN([FIND_QT],
     qtlibdir=`"$PKG_CONFIG" --variable libdir Qt5Core`
     if test -n "$qtlibdir"; then
       if test "$enable_rpath" != "no"; then
-        PINENTRY_QT_LDFLAGS="$PINENTRY_QT_LDFLAGS -Wl,-rpath \"$qtlibdir\""
+        PINENTRY_QT_LDFLAGS="$PINENTRY_QT_LDFLAGS -Wl,-rpath=\"$qtlibdir\""
       fi
     fi
 
