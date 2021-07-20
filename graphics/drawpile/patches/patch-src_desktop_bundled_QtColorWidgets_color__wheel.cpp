$NetBSD: patch-src_desktop_bundled_QtColorWidgets_color__wheel.cpp,v 1.1 2021/07/20 10:54:18 nia Exp $

Fix building with latest Qt.

--- src/desktop/bundled/QtColorWidgets/color_wheel.cpp.orig	2020-02-16 16:35:42.000000000 +0000
+++ src/desktop/bundled/QtColorWidgets/color_wheel.cpp
@@ -25,6 +25,7 @@
 #include <QtMath>
 #include <QMouseEvent>
 #include <QPainter>
+#include <QPainterPath>
 #include <QLineF>
 #include <QDragEnterEvent>
 #include <QMimeData>
