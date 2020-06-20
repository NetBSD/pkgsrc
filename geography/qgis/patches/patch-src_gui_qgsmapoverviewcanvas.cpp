$NetBSD: patch-src_gui_qgsmapoverviewcanvas.cpp,v 1.1 2020/06/20 17:52:05 gdt Exp $

Deal with QT 5.15, from upstream.
https://github.com/qgis/QGIS/issues/37005
https://github.com/qgis/QGIS/commit/31f586ec.patch

--- src/gui/qgsmapoverviewcanvas.cpp.orig	2019-09-13 12:11:09.000000000 +0000
+++ src/gui/qgsmapoverviewcanvas.cpp
@@ -24,6 +24,7 @@
 #include "qgsmaptopixel.h"
 
 #include <QPainter>
+#include <QPainterPath>
 #include <QPaintEvent>
 #include <QResizeEvent>
 #include <QMouseEvent>
