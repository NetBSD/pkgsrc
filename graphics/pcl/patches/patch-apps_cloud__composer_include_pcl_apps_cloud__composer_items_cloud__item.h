$NetBSD: patch-apps_cloud__composer_include_pcl_apps_cloud__composer_items_cloud__item.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/cloud_composer/include/pcl/apps/cloud_composer/items/cloud_item.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/cloud_composer/include/pcl/apps/cloud_composer/items/cloud_item.h
@@ -40,10 +40,17 @@
 #include <QDebug>
 
 #include <pcl/apps/cloud_composer/items/cloud_composer_item.h>
+
+#include <pcl/point_types.h>
+#include <pcl/point_cloud.h>
+#include <pcl/PCLPointCloud2.h>
 #include <pcl/memory.h>
 #include <pcl/pcl_macros.h>
-#include <pcl/visualization/pcl_visualizer.h>
 #include <pcl/search/kdtree.h>
+#include <pcl/visualization/point_cloud_geometry_handlers.h>
+#include <pcl/visualization/point_cloud_color_handlers.h>
+#include <pcl/visualization/pcl_visualizer.h>
+
 
 //Typedefs to make things sane
 using GeometryHandler = pcl::visualization::PointCloudGeometryHandler<pcl::PCLPointCloud2>;
