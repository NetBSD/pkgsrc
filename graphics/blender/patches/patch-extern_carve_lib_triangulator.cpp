$NetBSD: patch-extern_carve_lib_triangulator.cpp,v 1.1 2014/01/10 20:06:46 joerg Exp $

--- extern/carve/lib/triangulator.cpp.orig	2013-11-20 21:53:04.000000000 +0000
+++ extern/carve/lib/triangulator.cpp
@@ -122,7 +122,7 @@ namespace {
     std::vector<vertex_info *> queue;
 
     void checkheap() {
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(_LIBCPP_VERSION)
       CARVE_ASSERT(std::__is_heap(queue.begin(), queue.end(), vertex_info_ordering()));
 #endif
     }
