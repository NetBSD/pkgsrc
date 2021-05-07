$NetBSD: patch-visualization_include_pcl_visualization_qvtk__compatibility.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- visualization/include/pcl/visualization/qvtk_compatibility.h.orig	2021-05-06 06:26:06.674196977 +0000
+++ visualization/include/pcl/visualization/qvtk_compatibility.h
@@ -0,0 +1,51 @@
+/*
+ * SPDX-License-Identifier: BSD-3-Clause
+ *
+ *  Point Cloud Library (PCL) - www.pointclouds.org
+ *  Copyright (c) 2020-, Open Perception
+ *
+ *  All rights reserved
+ */
+#include <pcl/pcl_macros.h>
+#include <pcl/pcl_config.h>
+
+#if HAVE_QVTK
+#include <vtkVersion.h>
+#include <vtkRenderWindow.h>
+
+#if VTK_MAJOR_VERSION > 8
+  #include <QVTKOpenGLNativeWidget.h>
+  using PCLQVTKWidget = QVTKOpenGLNativeWidget;
+#else 
+  #include <QVTKWidget.h>
+  using PCLQVTKWidget = QVTKWidget;
+#endif // VTK_MAJOR_VERSION > 8
+
+
+inline auto PCL_EXPORTS getInteractorCompat(PCLQVTKWidget& qvtk) {
+#if VTK_MAJOR_VERSION > 8
+  return qvtk.interactor();
+#else
+  return qvtk.GetInteractor();
+#endif // VTK_MAJOR_VERSION > 8
+}
+
+inline auto PCL_EXPORTS getRenderWindowCompat(PCLQVTKWidget& qvtk) {
+#if VTK_MAJOR_VERSION > 8
+  return qvtk.renderWindow();
+#else
+  return qvtk.GetRenderWindow();
+#endif // VTK_MAJOR_VERSION > 8
+}
+
+inline auto PCL_EXPORTS setRenderWindowCompat(PCLQVTKWidget& qvtk, vtkRenderWindow& window) {
+#if VTK_MAJOR_VERSION > 8
+  return qvtk.setRenderWindow(&window);
+#else
+  return qvtk.SetRenderWindow(&window);
+#endif // VTK_MAJOR_VERSION > 8
+}
+
+#else
+#error PCL is not compiled with QVTK.
+#endif
