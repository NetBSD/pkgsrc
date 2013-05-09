$NetBSD: patch-src_data_hash__queue.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/data/hash_queue.cc.orig	2012-04-02 07:04:22.000000000 +0000
+++ src/data/hash_queue.cc
@@ -54,11 +54,17 @@
 #include "globals.h"
 #include "thread_disk.h"
 
+#if __cplusplus >= 201103L
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
+
 #define LT_LOG_DATA(data, log_level, log_fmt, ...)                       \
   lt_log_print_data(LOG_STORAGE_##log_level, data, "hash_queue", log_fmt, __VA_ARGS__);
 
-namespace tr1 { using namespace std::tr1; }
-
 namespace torrent {
 
 struct HashQueueEqual {
@@ -87,7 +93,7 @@ HashQueue::HashQueue(thread_disk* thread
   m_thread_disk(thread) {
 
   pthread_mutex_init(&m_done_chunks_lock, NULL);
-  m_thread_disk->hash_queue()->slot_chunk_done() = tr1::bind(&HashQueue::chunk_done, this, tr1::placeholders::_1, tr1::placeholders::_2);
+  m_thread_disk->hash_queue()->slot_chunk_done() = bind(&HashQueue::chunk_done, this, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2);
 }
 
 
@@ -176,9 +182,9 @@ HashQueue::work() {
     // TODO: This is not optimal as we jump around... Check for front
     // of HashQueue in done_chunks instead.
 
-    iterator itr = std::find_if(begin(), end(), tr1::bind(std::equal_to<HashChunk*>(),
+    iterator itr = std::find_if(begin(), end(), bind(std::equal_to<HashChunk*>(),
                                                           hash_chunk,
-                                                          tr1::bind(&HashQueueNode::get_chunk, tr1::placeholders::_1)));
+                                                          bind(&HashQueueNode::get_chunk, STD_PLACEHOLDERS::_1)));
 
     // TODO: Fix this...
     if (itr == end())
