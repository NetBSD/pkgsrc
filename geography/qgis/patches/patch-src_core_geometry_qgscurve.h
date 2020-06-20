$NetBSD: patch-src_core_geometry_qgscurve.h,v 1.1 2020/06/20 17:52:05 gdt Exp $

Deal with QT 5.15, from upstream.
https://github.com/qgis/QGIS/issues/37005
https://github.com/qgis/QGIS/commit/31f586ec.patch

--- src/core/geometry/qgscurve.h.orig	2019-09-13 12:11:09.000000000 +0000
+++ src/core/geometry/qgscurve.h
@@ -22,9 +22,9 @@
 #include "qgis_sip.h"
 #include "qgsabstractgeometry.h"
 #include "qgsrectangle.h"
+#include <QPainterPath>
 
 class QgsLineString;
-class QPainterPath;
 
 /**
  * \ingroup core
