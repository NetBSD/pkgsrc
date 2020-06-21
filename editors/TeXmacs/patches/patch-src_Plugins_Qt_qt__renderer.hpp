$NetBSD: patch-src_Plugins_Qt_qt__renderer.hpp,v 1.1 2020/06/21 03:54:54 mef Exp $

Adapt to QT 5.15.0

--- src/Plugins/Qt/qt_renderer.hpp.orig	2020-06-21 02:24:51.846185942 +0000
+++ src/Plugins/Qt/qt_renderer.hpp
@@ -18,6 +18,7 @@
 #include <QImage>
 #include <QtGlobal>
 #include <QWidget>
+#include <QPainterPath>
 
 // if QTMPIXMAPS is defined we use QPixmap for characters
 // otherwise we use QImage (which support alpha also under X11)
