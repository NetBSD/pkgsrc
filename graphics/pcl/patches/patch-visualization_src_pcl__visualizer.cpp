$NetBSD: patch-visualization_src_pcl__visualizer.cpp,v 1.4 2025/01/30 22:07:41 wiz Exp $

build of 1.14.1 fails with boost 1.86.0 #6157
https://github.com/PointCloudLibrary/pcl/issues/6157

--- visualization/src/pcl_visualizer.cpp.orig	2024-10-25 23:54:29.888728521 +0000
+++ visualization/src/pcl_visualizer.cpp
@@ -4592,7 +4592,10 @@ pcl::visualization::PCLVisualizer::getUn
     if (valid)
     {
       unsigned int digest[5];
-      sha1.get_digest (digest);
+      unsigned char digestchar[20];
+      sha1.get_digest (digestchar);
+      /* \todo Don't assume int is 32 bits! */
+      memcpy(digest, digestchar, 20);
       sstream << ".";
       sstream << std::hex << digest[0] << digest[1] << digest[2] << digest[3] << digest[4];
       sstream << ".cam";
