$NetBSD: patch-simulation_src_model.cpp,v 1.1 2021/05/07 11:36:29 thor Exp $

Support VTK 9, from PR 4262

--- simulation/src/model.cpp.orig	2020-08-14 12:23:03.000000000 +0000
+++ simulation/src/model.cpp
@@ -21,7 +21,7 @@ pcl::simulation::TriangleMeshModel::Tria
 
     Eigen::Vector4f tmp;
     for (const auto& polygon : plg->polygons) {
-      for (const unsigned int& point : polygon.vertices) {
+      for (const auto& point : polygon.vertices) {
         tmp = newcloud[point].getVector4fMap();
         vertices.push_back(Vertex(Eigen::Vector3f(tmp(0), tmp(1), tmp(2)),
                                   Eigen::Vector3f(newcloud[point].r / 255.0f,
@@ -36,7 +36,7 @@ pcl::simulation::TriangleMeshModel::Tria
     pcl::fromPCLPointCloud2(plg->cloud, newcloud);
     Eigen::Vector4f tmp;
     for (const auto& polygon : plg->polygons) {
-      for (const unsigned int& point : polygon.vertices) {
+      for (const auto& point : polygon.vertices) {
         tmp = newcloud[point].getVector4fMap();
         vertices.push_back(Vertex(Eigen::Vector3f(tmp(0), tmp(1), tmp(2)),
                                   Eigen::Vector3f(1.0, 1.0, 1.0)));
