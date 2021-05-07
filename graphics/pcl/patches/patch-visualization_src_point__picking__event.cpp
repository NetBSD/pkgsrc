$NetBSD: patch-visualization_src_point__picking__event.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/src/point_picking_event.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ visualization/src/point_picking_event.cpp
@@ -49,7 +49,6 @@
 #include <vtkPointData.h>
 #include <vtkVertexGlyphFilter.h>
 #include <vtkPlanes.h>
-#include <vtkXYPlotActor.h>
 #include <vtkRenderer.h>
 #include <vtkRenderWindow.h>
 
