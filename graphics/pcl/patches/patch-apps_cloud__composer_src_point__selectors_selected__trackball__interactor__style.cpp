$NetBSD: patch-apps_cloud__composer_src_point__selectors_selected__trackball__interactor__style.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/cloud_composer/src/point_selectors/selected_trackball_interactor_style.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/cloud_composer/src/point_selectors/selected_trackball_interactor_style.cpp
@@ -4,6 +4,15 @@
 #include <QDebug>
 #include <QItemSelectionModel>
 
+#include <vtkSmartPointer.h>
+#include <vtkMatrix4x4.h>
+#include <vtkLODActor.h>
+#include <vtkInteractorStyleTrackballActor.h>
+#include <vtkRenderWindowInteractor.h>
+#include <vtkTransform.h>
+#include <vtkObjectFactory.h>
+
+
 namespace pcl
 {
   namespace cloud_composer
