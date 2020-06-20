$NetBSD: patch-src_core_dxf_qgsdxfpaintengine.h,v 1.1 2020/06/20 17:52:05 gdt Exp $

Deal with QT 5.15, from upstream.
https://github.com/qgis/QGIS/issues/37005
https://github.com/qgis/QGIS/commit/31f586ec.patch

--- src/core/dxf/qgsdxfpaintengine.h.orig	2019-09-13 12:11:09.000000000 +0000
+++ src/core/dxf/qgsdxfpaintengine.h
@@ -22,6 +22,7 @@
 
 #include "qgis_core.h"
 #include <QPaintEngine>
+#include <QPainterPath>
 #include "qgsabstractgeometry.h"
 
 class QgsPoint;
