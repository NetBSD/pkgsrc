$NetBSD: patch-src_testrender_rapidobj_rapidobj.hpp,v 1.1 2026/11/08 15:03:18 ryoon Exp $

* Support NetBSD.

--- src/testrender/rapidobj/rapidobj.hpp.orig	2026-09-07 16:59:49.000000000 +0000
+++ src/testrender/rapidobj/rapidobj.hpp
@@ -43,7 +43,7 @@ OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH 
 #include <variant>
 #include <vector>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 
 #include <fcntl.h>
 #include <sys/stat.h>
@@ -4835,7 +4835,10 @@ namespace sys {
 
 namespace sys {
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
+#if defined(__NetBSD__)
+#define pread64 pread
+#endif
 
 inline auto AlignedAllocate(size_t size, size_t alignment)
 {
@@ -4902,7 +4905,9 @@ struct FileReader : Reader {
         m_size   = size;
         m_buffer = buffer;
 
+#if !defined(__NetBSD__)
         readahead(m_fd, offset, size);
+#endif
 
         auto t2 = std::chrono::steady_clock::now();
 
@@ -5203,6 +5208,10 @@ struct FileReader : Reader {
     size_t m_size{};
     char*  m_buffer{};
 };
+
+#if defined(__NetBSD__)
+#undef pread64
+#endif
 
 #endif
 
