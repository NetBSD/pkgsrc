$NetBSD: patch-src_qtterminal_QtGnuplotWidget.h,v 1.1 2024/06/05 13:56:14 adam Exp $

Use proper includes.

--- src/qtterminal/QtGnuplotWidget.h.orig	2024-05-16 11:56:34.675244242 +0000
+++ src/qtterminal/QtGnuplotWidget.h
@@ -46,12 +46,12 @@
 
 #include "QtGnuplotEvent.h"
 
-#include <QWidget>
-#include <QPainter>
+#include <QtWidgets/QWidget>
+#include <QtGui/QPainter>
 
 /* I had to add these in order to link against qt5 rather than qt4 */
 #if QT_VERSION >= 0x050000
-#include <QtWidgets>
+#include <QtWidgets/QtWidgets>
 #include <QtPrintSupport/QPrinter>
 #include <QtPrintSupport/QPrintDialog>
 #endif
