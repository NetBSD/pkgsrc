$NetBSD: patch-extern_carve_include_carve_mesh__ops.hpp,v 1.1 2014/04/17 20:20:25 joerg Exp $

--- extern/carve/include/carve/mesh_ops.hpp.orig	2014-04-17 15:04:25.000000000 +0000
+++ extern/carve/include/carve/mesh_ops.hpp
@@ -580,7 +580,7 @@ namespace carve {
           std::vector<VertexInfo *> queue;
 
           void checkheap() {
-#ifdef __GNUC__
+#ifdef __GLIBCXX__
             CARVE_ASSERT(std::__is_heap(queue.begin(), queue.end(), order_by_score()));
 #endif
           }
