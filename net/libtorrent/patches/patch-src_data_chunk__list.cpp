$NetBSD: patch-src_data_chunk__list.cpp,v 1.4 2017/12/26 23:14:42 he Exp $

Add some casts now required.

--- src/data/chunk_list.cc.orig	2012-02-22 07:50:27.000000000 +0000
+++ src/data/chunk_list.cc	2013-05-12 12:25:45.000000000 +0100
@@ -368,19 +368,19 @@
   if (flags & sync_force) {
 
     if (flags & sync_safe)
-      return std::make_pair(MemoryChunk::sync_sync, true);
+      return std::make_pair((int)MemoryChunk::sync_sync, true);
     else
-      return std::make_pair(MemoryChunk::sync_async, true);
+      return std::make_pair((int)MemoryChunk::sync_async, true);
 
   } else if (flags & sync_safe) {
       
     if (node->sync_triggered())
-      return std::make_pair(MemoryChunk::sync_sync, true);
+      return std::make_pair((int)MemoryChunk::sync_sync, true);
     else
-      return std::make_pair(MemoryChunk::sync_async, false);
+      return std::make_pair((int)MemoryChunk::sync_async, false);
 
   } else {
-    return std::make_pair(MemoryChunk::sync_async, true);
+    return std::make_pair((int)MemoryChunk::sync_async, true);
   }
 }
 
