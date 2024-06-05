$NetBSD: patch-src_qtterminal_qt__embed__example.h,v 1.1 2024/06/05 13:56:14 adam Exp $

--- src/qtterminal/qt_embed_example.h.orig	2024-05-16 12:08:20.647170315 +0000
+++ src/qtterminal/qt_embed_example.h
@@ -48,7 +48,7 @@
 
 #include <QtCore>
 #include <QtGui>
-#include <QWidget>
+#include <QtWidgets/QWidget>
 
 class QtGnuplotWidget;
 class QPlainTextEdit;
