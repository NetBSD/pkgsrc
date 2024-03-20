$NetBSD: patch-m4_qt5.m4,v 1.1 2024/03/20 15:46:37 adam Exp $

The "-rpath" option requires an equal sign.

--- m4/qt5.m4.orig	2023-03-20 07:10:22.000000000 +0000
+++ m4/qt5.m4
@@ -59,7 +59,7 @@ AC_DEFUN([FIND_QT5],
     qt5libdir=`"$PKG_CONFIG" --variable libdir Qt5Core`
     if test -n "$qt5libdir"; then
       if test "$enable_rpath" != "no"; then
-        PINENTRY_QT5_LDFLAGS="$PINENTRY_QT5_LDFLAGS -Wl,-rpath \"$qt5libdir\""
+        PINENTRY_QT5_LDFLAGS="$PINENTRY_QT5_LDFLAGS -Wl,-rpath=\"$qt5libdir\""
       fi
     fi
 
