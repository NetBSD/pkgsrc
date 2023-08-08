$NetBSD: patch-src_storage_local_LocalStorage.cpp,v 1.1 2023/08/08 12:54:14 tnn Exp $

Work around ICE with GCC 12.3.
https://github.com/ccache/ccache/commit/689168c292f1ed26c5f4a3070aeb649dad7facb5.patch

--- src/storage/local/LocalStorage.cpp.orig	2023-08-08 12:48:56.432136174 +0000
+++ src/storage/local/LocalStorage.cpp
@@ -708,7 +708,9 @@ LocalStorage::recompress(const std::opti
           auto l2_content_lock = get_level_2_content_lock(l1_index, l2_index);
           l2_content_lock.make_long_lived(lock_manager);
           if (!l2_content_lock.acquire()) {
-            LOG("Failed to acquire content lock for {}/{}", l1_index, l2_index);
+            // LOG_RAW+fmt::format instead of LOG due to GCC 12.3 bug #109241
+            LOG_RAW(fmt::format(
+              "Failed to acquire content lock for {}/{}", l1_index, l2_index));
             return;
           }
 
