$NetBSD: patch-src_qtterminal_QtGnuplotApplication.h,v 1.1 2024/06/05 13:56:14 adam Exp $

Use proper includes.

--- src/qtterminal/QtGnuplotApplication.h.orig	2024-05-16 12:06:43.607251330 +0000
+++ src/qtterminal/QtGnuplotApplication.h
@@ -46,8 +46,8 @@
 
 #include "QtGnuplotEvent.h"
 
-#include <QApplication>
-#include <QMap>
+#include <QtWidgets/QApplication>
+#include <QtCore/QMap>
 
 class QtGnuplotWindow;
 
