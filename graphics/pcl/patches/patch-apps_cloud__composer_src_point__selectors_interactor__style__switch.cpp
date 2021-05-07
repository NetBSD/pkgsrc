$NetBSD: patch-apps_cloud__composer_src_point__selectors_interactor__style__switch.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/cloud_composer/src/point_selectors/interactor_style_switch.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/cloud_composer/src/point_selectors/interactor_style_switch.cpp
@@ -6,6 +6,9 @@
 
 #include <QDebug>
 
+#include <vtkCallbackCommand.h>
+#include <vtkObjectFactory.h>
+
 namespace pcl
 {
   namespace cloud_composer
