$NetBSD: patch-src_dirnode.cpp,v 1.2 2012/12/19 13:50:35 ryoon Exp $

* Fix build failure with gcc 4.7 (and 5.4.4)

--- src/dirnode.cpp.orig	2012-04-20 01:52:29.000000000 +0000
+++ src/dirnode.cpp
@@ -577,7 +577,7 @@ void RDirNode::calcRadius() {
     //this->dir_radius_sqrt = sqrt(dir_radius); //dir_radius_sqrt is not used
 
 //    this->parent_radius = std::max(1.0, parent_circ / PI);
-    this->parent_radius = std::max(1.0, sqrt(total_file_area) * gGourceDirPadding);
+    this->parent_radius = std::max(1.0f, (float) (sqrt(total_file_area) * gGourceDirPadding));
 }
 
 float RDirNode::distanceToParent() const{
