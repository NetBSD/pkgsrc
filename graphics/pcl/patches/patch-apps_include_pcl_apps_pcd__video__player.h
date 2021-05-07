$NetBSD: patch-apps_include_pcl_apps_pcd__video__player.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/include/pcl/apps/pcd_video_player.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/include/pcl/apps/pcd_video_player.h
@@ -53,7 +53,6 @@
 #include <QMainWindow>
 #include <QMutex>
 #include <QTimer>
-#include <ui_pcd_video_player.h>
 
 #include <ctime>
 #include <iostream>
@@ -93,6 +92,9 @@ public:
   ~PCDVideoPlayer() {}
 
 protected:
+  void
+  refreshView();
+
   pcl::visualization::PCLVisualizer::Ptr vis_;
   pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_;
 
