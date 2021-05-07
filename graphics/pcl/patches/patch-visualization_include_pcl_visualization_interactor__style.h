$NetBSD: patch-visualization_include_pcl_visualization_interactor__style.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/include/pcl/visualization/interactor_style.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ visualization/include/pcl/visualization/interactor_style.h
@@ -51,6 +51,8 @@
 #include <boost/signals2/signal.hpp>
 #endif
 #include <vtkInteractorStyleRubberBandPick.h>
+#include <vtkRendererCollection.h>
+#include <vtkRenderWindow.h>
 
 class vtkRendererCollection;
 class vtkLegendScaleActor;
