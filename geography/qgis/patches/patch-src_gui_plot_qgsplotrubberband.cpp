$NetBSD: patch-src_gui_plot_qgsplotrubberband.cpp,v 1.1 2022/11/28 14:25:31 gdt Exp $

Use standards-required include for std::fabs().

Reported upstream at https://github.com/qgis/QGIS/pull/51040

--- src/gui/plot/qgsplotrubberband.cpp.orig	2022-11-18 12:10:21.000000000 +0000
+++ src/gui/plot/qgsplotrubberband.cpp
@@ -20,7 +20,7 @@
 
 #include <QGraphicsScene>
 #include <QGraphicsRectItem>
-#include <math.h>
+#include <cmath>
 
 QgsPlotRubberBand::QgsPlotRubberBand( QgsPlotCanvas *canvas )
   : mCanvas( canvas )
