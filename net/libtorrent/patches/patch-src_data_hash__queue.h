$NetBSD: patch-src_data_hash__queue.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/data/hash_queue.h.orig	2012-02-17 05:00:42.000000000 +0000
+++ src/data/hash_queue.h
@@ -40,7 +40,13 @@
 #include <deque>
 #include <map>
 #include <pthread.h>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 
 #include "torrent/hash_string.h"
 #include "hash_queue_node.h"
@@ -63,7 +69,7 @@ public:
   typedef std::map<HashChunk*, torrent::HashString> done_chunks_type;
 
   typedef HashQueueNode::slot_done_type   slot_done_type;
-  typedef std::tr1::function<void (bool)> slot_bool;
+  typedef function<void (bool)> slot_bool;
 
   using base_type::iterator;
 
