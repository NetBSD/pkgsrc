$NetBSD: patch-apps_include_pcl_apps_nn__classification.h,v 1.1 2021/05/08 22:04:58 thor Exp $

Uses FLT_MAX without the header for it.

--- apps/include/pcl/apps/nn_classification.h.orig	2021-05-08 19:13:27.461692381 +0000
+++ apps/include/pcl/apps/nn_classification.h
@@ -41,6 +41,7 @@
 
 #include <pcl/io/pcd_io.h>
 #include <pcl/kdtree/kdtree_flann.h>
+#include <cfloat>
 
 namespace pcl {
 
