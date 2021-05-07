$NetBSD: patch-apps_cloud__composer_src_project__model.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/cloud_composer/src/project_model.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/cloud_composer/src/project_model.cpp
@@ -14,6 +14,11 @@
 #include <QMessageBox>
 #include <QThread>
 
+#include <vtkSmartPointer.h>
+#include <vtkImageData.h>
+#include <vtkImageReader2Factory.h>
+#include <vtkImageReader2.h>
+
 pcl::cloud_composer::ProjectModel::ProjectModel (QObject* parent)
   : QStandardItemModel (parent)
 {
