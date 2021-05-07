$NetBSD: patch-apps_modeler_include_pcl_apps_modeler_render__window.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/modeler/include/pcl/apps/modeler/render_window.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/modeler/include/pcl/apps/modeler/render_window.h
@@ -35,8 +35,7 @@
  */
 
 #pragma once
-
-#include <QVTKWidget.h>
+#include <pcl/visualization/qvtk_compatibility.h>
 
 #include <vtkSmartPointer.h>
 
@@ -47,7 +46,7 @@ namespace modeler {
 
 class RenderWindowItem;
 
-class RenderWindow : public QVTKWidget {
+class RenderWindow : public PCLQVTKWidget {
 public:
   RenderWindow(RenderWindowItem* render_window_item,
                QWidget* parent = nullptr,
