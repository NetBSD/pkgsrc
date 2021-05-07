$NetBSD: patch-apps_cloud__composer_include_pcl_apps_cloud__composer_point__selectors_interactor__style__switch.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/cloud_composer/include/pcl/apps/cloud_composer/point_selectors/interactor_style_switch.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/cloud_composer/include/pcl/apps/cloud_composer/point_selectors/interactor_style_switch.h
@@ -39,12 +39,19 @@
 
 #include <QMap>
 
-#include <pcl/visualization/vtk.h>
 #include <pcl/visualization/interactor_style.h>
 #include <pcl/visualization/common/actor_map.h>
 #include <pcl/visualization/common/ren_win_interact_map.h>
 #include <pcl/visualization/pcl_visualizer.h>
 
+#include <vtkSmartPointer.h>
+#include <vtkAreaPicker.h>
+#include <vtkPointPicker.h>
+#include <vtkRenderWindowInteractor.h>
+#include <vtkCommand.h>
+#include <vtkRendererCollection.h>
+#include <vtkInteractorStyle.h>
+
 class QVTKWidget;
 
 namespace pcl
