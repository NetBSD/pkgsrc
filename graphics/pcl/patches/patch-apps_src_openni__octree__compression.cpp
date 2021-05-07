$NetBSD: patch-apps_src_openni__octree__compression.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- apps/src/openni_octree_compression.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ apps/src/openni_octree_compression.cpp
@@ -382,7 +382,7 @@ main(int argc, char** argv)
   if (!bServerFileMode) {
     if (bEnDecode) {
       // ENCODING
-      ofstream compressedPCFile;
+      std::ofstream compressedPCFile;
       compressedPCFile.open(fileName.c_str(), std::ios::out | std::ios::trunc | std::ios::binary);
 
       if (!bShowInputCloud) {
