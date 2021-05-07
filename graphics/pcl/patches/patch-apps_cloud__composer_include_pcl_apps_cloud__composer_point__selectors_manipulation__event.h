$NetBSD: patch-apps_cloud__composer_include_pcl_apps_cloud__composer_point__selectors_manipulation__event.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/cloud_composer/include/pcl/apps/cloud_composer/point_selectors/manipulation_event.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/cloud_composer/include/pcl/apps/cloud_composer/point_selectors/manipulation_event.h
@@ -37,7 +37,6 @@
 
 #pragma once
 
-#include <pcl/visualization/vtk.h>
 #include <pcl/apps/cloud_composer/items/cloud_item.h>
 
 namespace pcl
