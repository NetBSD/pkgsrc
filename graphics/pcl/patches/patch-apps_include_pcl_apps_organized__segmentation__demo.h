$NetBSD: patch-apps_include_pcl_apps_organized__segmentation__demo.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/include/pcl/apps/organized_segmentation_demo.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/include/pcl/apps/organized_segmentation_demo.h
@@ -189,4 +189,8 @@ public Q_SLOTS:
 private Q_SLOTS:
   void
   timeoutSlot();
+
+private:
+  void
+  refreshView();
 };
