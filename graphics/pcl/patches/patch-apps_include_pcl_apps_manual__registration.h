$NetBSD: patch-apps_include_pcl_apps_manual__registration.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/include/pcl/apps/manual_registration.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/include/pcl/apps/manual_registration.h
@@ -106,6 +106,9 @@ public:
   DstPointPickCallback(const pcl::visualization::PointPickingEvent& event, void*);
 
 protected:
+  void
+  refreshView();
+
   pcl::visualization::PCLVisualizer::Ptr vis_src_;
   pcl::visualization::PCLVisualizer::Ptr vis_dst_;
 
