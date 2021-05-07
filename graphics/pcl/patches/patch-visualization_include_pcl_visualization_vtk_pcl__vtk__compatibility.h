$NetBSD: patch-visualization_include_pcl_visualization_vtk_pcl__vtk__compatibility.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/include/pcl/visualization/vtk/pcl_vtk_compatibility.h.orig	2021-05-06 06:26:06.674196977 +0000
+++ visualization/include/pcl/visualization/vtk/pcl_vtk_compatibility.h
@@ -0,0 +1,17 @@
+/*
+ * SPDX-License-Identifier: BSD-3-Clause
+ *
+ *  Point Cloud Library (PCL) - www.pointclouds.org
+ *  Copyright (c) 2020-, Open Perception
+ *
+ *  All rights reserved
+ */
+
+#include <vtkCellArray.h>
+
+#ifdef VTK_CELL_ARRAY_V2
+  using vtkCellPtsPtr = vtkIdType const*;
+#else
+  using vtkCellPtsPtr = vtkIdType*;
+#endif
+
