$NetBSD: patch-apps_cloud__composer_include_pcl_apps_cloud__composer_items_fpfh__item.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/cloud_composer/include/pcl/apps/cloud_composer/items/fpfh_item.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/cloud_composer/include/pcl/apps/cloud_composer/items/fpfh_item.h
@@ -41,10 +41,9 @@
 #include <pcl/features/fpfh.h>
 
 #include <pcl/apps/cloud_composer/items/cloud_composer_item.h>
+#include <pcl/visualization/qvtk_compatibility.h>
 #include <pcl/visualization/pcl_plotter.h>
 
-class QVTKWidget;
-
 namespace pcl
 {
   namespace cloud_composer
@@ -74,7 +73,7 @@ namespace pcl
         pcl::PointCloud<pcl::FPFHSignature33>::Ptr fpfh_ptr_;
         double radius_;
         pcl::visualization::PCLPlotter::Ptr plot_;
-        QVTKWidget *qvtk_;
+        PCLQVTKWidget* qvtk_;
         QWidget *hist_page_;
     };
 
