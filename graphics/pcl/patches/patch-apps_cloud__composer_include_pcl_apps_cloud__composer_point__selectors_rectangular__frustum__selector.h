$NetBSD: patch-apps_cloud__composer_include_pcl_apps_cloud__composer_point__selectors_rectangular__frustum__selector.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/cloud_composer/include/pcl/apps/cloud_composer/point_selectors/rectangular_frustum_selector.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/cloud_composer/include/pcl/apps/cloud_composer/point_selectors/rectangular_frustum_selector.h
@@ -39,6 +39,10 @@
 
 #include <pcl/apps/cloud_composer/point_selectors/interactor_style_switch.h>
 
+#include <vtkSmartPointer.h>
+#include <vtkRendererCollection.h>
+#include <vtkInteractorStyleRubberBandPick.h>
+
 namespace pcl
 {
   namespace cloud_composer
