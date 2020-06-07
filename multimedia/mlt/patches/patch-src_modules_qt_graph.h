$NetBSD: patch-src_modules_qt_graph.h,v 1.1 2020/06/07 04:35:25 markd Exp $

build with qt5.15

--- src/modules/qt/graph.h.orig	2020-02-16 22:31:58.000000000 +0000
+++ src/modules/qt/graph.h
@@ -22,6 +22,7 @@
 
 #include <framework/mlt.h>
 #include <QPainter>
+#include <QPainterPath>
 #include <QRectF>
 
 void setup_graph_painter( QPainter& p, QRectF& rect, mlt_properties filter_properties );
