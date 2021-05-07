$NetBSD: patch-visualization_include_pcl_visualization_common_ren__win__interact__map.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/include/pcl/visualization/common/ren_win_interact_map.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ visualization/include/pcl/visualization/common/ren_win_interact_map.h
@@ -41,8 +41,9 @@
 #include <map>
 #include <string>
 
+#include <vtkXYPlotActor.h>
+
 template <typename T> class vtkSmartPointer;
-class vtkXYPlotActor;
 class vtkRenderer;
 class vtkRenderWindow;
 class vtkRenderWindowInteractor;
