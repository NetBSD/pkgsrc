$NetBSD: patch-src_util_memory__arena.h,v 1.1 2023/11/14 17:57:41 nia Exp $

NetBSD (and more POSIX platforms) support.

--- src/util/memory_arena.h.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/util/memory_arena.h
@@ -65,7 +65,7 @@ public:
 private:
 #if defined(_WIN32)
   void* m_file_handle = nullptr;
-#elif defined(__linux__) || defined(ANDROID) || defined(__APPLE__) || defined(__FreeBSD__)
+#else
   int m_shmem_fd = -1;
 #endif
 
