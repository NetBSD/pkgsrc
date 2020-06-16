$NetBSD: patch-librecad_src_lib_engine_lc__splinepoints.cpp,v 1.1 2020/06/16 14:43:17 mef Exp $

Adapt for boost update

--- librecad/src/lib/engine/lc_splinepoints.cpp.orig	2018-02-15 20:54:45.000000000 +0000
+++ librecad/src/lib/engine/lc_splinepoints.cpp
@@ -22,6 +22,8 @@ Foundation, Inc., 51 Franklin Street, Fi
 **********************************************************************/
 
 #include <QPolygonF>
+#include <QPainterPath>
+
 #include "lc_splinepoints.h"
 
 #include "rs_circle.h"
