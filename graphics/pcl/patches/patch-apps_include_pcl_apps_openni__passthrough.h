$NetBSD: patch-apps_include_pcl_apps_openni__passthrough.h,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/include/pcl/apps/openni_passthrough.h.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/include/pcl/apps/openni_passthrough.h
@@ -86,6 +86,9 @@ public:
   cloud_cb(const CloudConstPtr& cloud);
 
 protected:
+  void
+  refreshView();
+  
   pcl::visualization::PCLVisualizer::Ptr vis_;
   pcl::OpenNIGrabber& grabber_;
   std::string device_id_;
