$NetBSD: patch-tools_virtual__scanner.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- tools/virtual_scanner.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ tools/virtual_scanner.cpp
@@ -54,7 +54,12 @@
 #include <pcl/memory.h>  // for pcl::make_shared
 #include <pcl/point_types.h>
 #include <pcl/console/parse.h>
-#include <pcl/visualization/vtk.h>
+
+#include <vtkGeneralTransform.h>
+#include <vtkPlatonicSolidSource.h>
+#include <vtkLoopSubdivisionFilter.h>
+#include <vtkCellLocator.h>
+#include <vtkMath.h>
 
 #include <boost/algorithm/string.hpp>  // for boost::is_any_of, boost::split, boost::token_compress_on, boost::trim
 #include <boost/filesystem.hpp>  // for boost::filesystem::create_directories, boost::filesystem::exists, boost::filesystem::extension, boost::filesystem::path
