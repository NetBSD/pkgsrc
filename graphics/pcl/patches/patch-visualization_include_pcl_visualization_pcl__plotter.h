$NetBSD: patch-visualization_include_pcl_visualization_pcl__plotter.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/include/pcl/visualization/pcl_plotter.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ visualization/include/pcl/visualization/pcl_plotter.h
@@ -49,16 +49,16 @@
 #include <pcl/point_cloud.h>
 #include <pcl/common/io.h>
 
-class vtkRenderWindow;
-class vtkRenderWindowInteractor;
-class vtkContextView;
-class vtkChartXY;
-class vtkColorSeries;
-
+#include <vtkContextView.h>
+#include <vtkChartXY.h>
+#include <vtkColorSeries.h>
 #include <vtkSmartPointer.h>
 #include <vtkCommand.h>
 #include <vtkChart.h>
 
+class vtkRenderWindow;
+class vtkRenderWindowInteractor;
+
 namespace pcl
 {
   namespace visualization
