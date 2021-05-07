$NetBSD: patch-visualization_src_histogram__visualizer.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/src/histogram_visualizer.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ visualization/src/histogram_visualizer.cpp
@@ -45,7 +45,6 @@
 #include <pcl/visualization/boost.h>
 
 #include <vtkVersion.h>
-#include <vtkXYPlotActor.h>
 #include <vtkDoubleArray.h>
 #include <vtkTextProperty.h>
 #include <vtkRenderWindow.h>
