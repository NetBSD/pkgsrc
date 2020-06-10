
qt5.15 fix
$NetBSD: patch-core_libs_dimg_filters_curves_curveswidget.cpp,v 1.1 2020/06/10 11:08:05 markd Exp $

--- core/libs/dimg/filters/curves/curveswidget.cpp.orig	2019-11-03 09:03:59.000000000 +0000
+++ core/libs/dimg/filters/curves/curveswidget.cpp
@@ -32,6 +32,7 @@
 
 #include <QPixmap>
 #include <QPainter>
+#include <QPainterPath>
 #include <QPoint>
 #include <QPen>
 #include <QEvent>
