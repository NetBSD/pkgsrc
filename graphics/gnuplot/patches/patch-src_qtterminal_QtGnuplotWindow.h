$NetBSD: patch-src_qtterminal_QtGnuplotWindow.h,v 1.1 2024/06/05 13:56:14 adam Exp $

Use proper includes.

--- src/qtterminal/QtGnuplotWindow.h.orig	2024-05-16 11:59:19.466156816 +0000
+++ src/qtterminal/QtGnuplotWindow.h
@@ -46,11 +46,11 @@
 
 #include "QtGnuplotEvent.h"
 
-#include <QMainWindow>
+#include <QtWidgets/QMainWindow>
 
 /* I had to add these in order to link against qt5 rather than qt4 */
 #if QT_VERSION >= 0x050000
-#include <QtWidgets>
+#include <QtWidgets/QtWidgets>
 #endif
 
 class QLabel;
