$NetBSD: patch-src_data_memory__chunk.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/data/memory_chunk.h.orig	2012-01-19 10:19:26.000000000 +0000
+++ src/data/memory_chunk.h
@@ -49,28 +49,30 @@ class MemoryChunk {
   // Consider information about whetever the memory maps to a file or
   // not, since mincore etc can only be called on files.
 
-  static const int prot_exec              = PROT_EXEC;
-  static const int prot_read              = PROT_READ;
-  static const int prot_write             = PROT_WRITE;
-  static const int prot_none              = PROT_NONE;
-  static const int map_shared             = MAP_SHARED;
+  enum {
+    prot_exec              = PROT_EXEC,
+    prot_read              = PROT_READ,
+    prot_write             = PROT_WRITE,
+    prot_none              = PROT_NONE,
+    map_shared             = MAP_SHARED,
 
 #ifdef USE_MADVISE
-  static const int advice_normal          = MADV_NORMAL;
-  static const int advice_random          = MADV_RANDOM;
-  static const int advice_sequential      = MADV_SEQUENTIAL;
-  static const int advice_willneed        = MADV_WILLNEED;
-  static const int advice_dontneed        = MADV_DONTNEED;
+    advice_normal          = MADV_NORMAL,
+    advice_random          = MADV_RANDOM,
+    advice_sequential      = MADV_SEQUENTIAL,
+    advice_willneed        = MADV_WILLNEED,
+    advice_dontneed        = MADV_DONTNEED,
 #else
-  static const int advice_normal          = 0;
-  static const int advice_random          = 1;
-  static const int advice_sequential      = 2;
-  static const int advice_willneed        = 3;
-  static const int advice_dontneed        = 4;
+    advice_normal          = 0,
+    advice_random          = 1,
+    advice_sequential      = 2,
+    advice_willneed        = 3,
+    advice_dontneed        = 4,
 #endif
-  static const int sync_sync              = MS_SYNC;
-  static const int sync_async             = MS_ASYNC;
-  static const int sync_invalidate        = MS_INVALIDATE;
+    sync_sync              = MS_SYNC,
+    sync_async             = MS_ASYNC,
+    sync_invalidate        = MS_INVALIDATE
+  };
 
   MemoryChunk() { clear(); }
   ~MemoryChunk() { clear(); }
