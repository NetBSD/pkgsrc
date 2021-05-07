$NetBSD: patch-apps_cloud__composer_src_point__selectors_rectangular__frustum__selector.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/cloud_composer/src/point_selectors/rectangular_frustum_selector.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/cloud_composer/src/point_selectors/rectangular_frustum_selector.cpp
@@ -3,6 +3,14 @@
 
 #include <QDebug>
 
+#include <vtkSmartPointer.h>
+#include <vtkIdFilter.h>
+#include <vtkExtractGeometry.h>
+#include <vtkVertexGlyphFilter.h>
+#include <vtkPlanes.h>
+#include <vtkAreaPicker.h>
+#include <vtkObjectFactory.h>
+
 namespace pcl
 {
   namespace cloud_composer
