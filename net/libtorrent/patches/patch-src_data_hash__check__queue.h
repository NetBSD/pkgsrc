$NetBSD: patch-src_data_hash__check__queue.h,v 1.3 2013/09/18 16:32:05 joerg Exp $

--- src/data/hash_check_queue.h.orig	2012-02-14 03:15:27.000000000 +0000
+++ src/data/hash_check_queue.h
@@ -39,7 +39,13 @@
 
 #include <deque>
 #include <pthread.h>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 
 #include "rak/allocators.h"
 
@@ -51,7 +57,7 @@ class HashChunk;
 class lt_cacheline_aligned HashCheckQueue : private std::deque<HashChunk*, rak::cacheline_allocator<HashChunk*> > {
 public:
   typedef std::deque<HashChunk*, rak::cacheline_allocator<HashChunk*> > base_type;
-  typedef std::tr1::function<void (HashChunk*, const HashString&)>      slot_chunk_handle;
+  typedef function<void (HashChunk*, const HashString&)>      slot_chunk_handle;
 
   using base_type::iterator;
 
