$NetBSD: patch-src_data_hash__queue__node.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/data/hash_queue_node.h.orig	2012-03-20 15:10:16.000000000 +0000
+++ src/data/hash_queue_node.h
@@ -38,7 +38,13 @@
 #define LIBTORRENT_DATA_HASH_QUEUE_NODE_H
 
 #include <string>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 #include <inttypes.h>
 
 #include "chunk_handle.h"
@@ -50,7 +56,7 @@ class download_data;
 
 class HashQueueNode {
 public:
-  typedef std::tr1::function<void (ChunkHandle, const char*)> slot_done_type;
+  typedef function<void (ChunkHandle, const char*)> slot_done_type;
   typedef download_data* id_type;
 
   HashQueueNode(id_type id, HashChunk* c, slot_done_type d) :
