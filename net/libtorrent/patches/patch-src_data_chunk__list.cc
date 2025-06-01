$NetBSD: patch-src_data_chunk__list.cc,v 1.2 2025/06/01 17:38:28 adam Exp $

Add some casts now required.

--- src/data/chunk_list.cc.orig	2025-06-01 13:08:42.000000000 +0000
+++ src/data/chunk_list.cc
@@ -329,18 +329,18 @@ std::pair<int, bool>
 ChunkList::sync_options(ChunkListNode* node, sync_flags flags) {
   if ((flags & sync_force)) {
     if ((flags & sync_safe))
-      return std::make_pair(MemoryChunk::sync_sync, true);
+      return std::make_pair((int)MemoryChunk::sync_sync, true);
     else
-      return std::make_pair(MemoryChunk::sync_async, true);
+      return std::make_pair((int)MemoryChunk::sync_async, true);
 
   } else if ((flags & sync_safe)) {
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
 
