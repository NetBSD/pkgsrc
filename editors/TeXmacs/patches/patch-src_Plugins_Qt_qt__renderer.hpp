$NetBSD: patch-src_Plugins_Qt_qt__renderer.hpp,v 1.2 2026/11/09 10:45:17 nros Exp $

Adapt to QT 5.15.0

--- src/Plugins/Qt/qt_renderer.hpp.orig	2026-03-09 21:55:57.000000000 +0000
+++ src/Plugins/Qt/qt_renderer.hpp
@@ -19,6 +19,7 @@
 #include <QImage>
 #include <QtGlobal>
 #include <QWidget>
+#include <QPainterPath>
 
 class qt_renderer_rep:  public basic_renderer_rep {
 public:
