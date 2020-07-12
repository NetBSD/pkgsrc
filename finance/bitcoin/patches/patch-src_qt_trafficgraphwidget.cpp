$NetBSD: patch-src_qt_trafficgraphwidget.cpp,v 1.1 2020/07/12 21:02:12 adam Exp $

Add missing include.

--- src/qt/trafficgraphwidget.cpp.orig	2020-07-09 18:14:46.000000000 +0000
+++ src/qt/trafficgraphwidget.cpp
@@ -9,6 +9,7 @@
 #include <QPainter>
 #include <QColor>
 #include <QTimer>
+#include <QPainterPath>
 
 #include <cmath>
 
