$NetBSD: patch-src_data_chunk__list.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/data/chunk_list.h.orig	2012-02-19 09:28:55.000000000 +0000
+++ src/data/chunk_list.h
@@ -39,7 +39,13 @@
 
 #include <string>
 #include <vector>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 
 #include "chunk.h"
 #include "chunk_handle.h"
@@ -59,9 +65,9 @@ public:
   typedef std::vector<ChunkListNode>          base_type;
   typedef std::vector<ChunkListNode*>         Queue;
 
-  typedef std::tr1::function<Chunk* (uint32_t, int)>    slot_chunk_index;
-  typedef std::tr1::function<uint64_t ()>               slot_value;
-  typedef std::tr1::function<void (const std::string&)> slot_string;
+  typedef function<Chunk* (uint32_t, int)>    slot_chunk_index;
+  typedef function<uint64_t ()>               slot_value;
+  typedef function<void (const std::string&)> slot_string;
 
   using base_type::value_type;
   using base_type::reference;
