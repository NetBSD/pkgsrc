$NetBSD: patch-apps_cloud__composer_include_pcl_apps_cloud__composer_cloud__view.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/cloud_composer/include/pcl/apps/cloud_composer/cloud_view.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/cloud_composer/include/pcl/apps/cloud_composer/cloud_view.h
@@ -42,8 +42,15 @@
 #include <vtkEventQtSlotConnect.h>
 
 #include <pcl/visualization/pcl_visualizer.h>
+#include <pcl/visualization/qvtk_compatibility.h>
 #include <pcl/apps/cloud_composer/point_selectors/interactor_style_switch.h>
 
+
+#include <vtkSmartPointer.h>
+#include <vtkOrientationMarkerWidget.h>
+#include <vtkAxesActor.h>
+#include <vtkVersion.h>
+
 class QItemSelection;
 class QStandardItem;
 
@@ -67,11 +74,12 @@ namespace pcl
       
       void 
       setModel (ProjectModel* new_model);
+      
       ProjectModel* 
       getModel () const { return model_; }
       
-      QVTKWidget* 
-      getQVTK() const {return qvtk_; }
+      PCLQVTKWidget*
+      getQVTK() const { return qvtk_; }
       
       pcl::visualization::PCLVisualizer::Ptr
       getPCLVisualizer () const { return vis_; }
@@ -141,7 +149,9 @@ namespace pcl
       
       pcl::visualization::PCLVisualizer::Ptr vis_;
       ProjectModel* model_;
-      QVTKWidget* qvtk_;
+
+      PCLQVTKWidget* qvtk_;
+
       vtkSmartPointer<InteractorStyleSwitch> style_switch_;
       
       vtkSmartPointer<vtkOrientationMarkerWidget> axes_widget_;
