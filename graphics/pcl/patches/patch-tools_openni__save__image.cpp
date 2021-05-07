$NetBSD: patch-tools_openni__save__image.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- tools/openni_save_image.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ tools/openni_save_image.cpp
@@ -39,9 +39,13 @@
 #include <pcl/io/openni_grabber.h>
 #include <pcl/io/openni_camera/openni_driver.h>
 #include <pcl/console/parse.h>
-#include <pcl/visualization/vtk.h>
 #include <pcl/visualization/pcl_visualizer.h>
 
+#include <vtkSmartPointer.h>
+#include <vtkImageImport.h>
+#include <vtkTIFFWriter.h>
+#include <vtkImageFlip.h>
+
 #include "boost.h"
 
 #include <mutex>
