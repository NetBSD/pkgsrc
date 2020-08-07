$NetBSD: patch-src_unix_freebsd.c,v 1.1 2020/08/07 11:30:53 adam Exp $

Fix DragonFly BSD build, https://github.com/libuv/libuv/pull/2952.

--- src/unix/freebsd.c.orig	2020-08-07 11:24:40.000000000 +0000
+++ src/unix/freebsd.c
@@ -58,7 +58,8 @@ void uv__platform_loop_delete(uv_loop_t*
 
 
 #ifdef __DragonFly__
-int uv_exepath(char* buffer, size_t* size) {
+/* deprecated long ago, use KERN_PROC_PATHNAME sysctl */
+int uv_exepath_procfs(char* buffer, size_t* size) {
   char abspath[PATH_MAX * 2 + 1];
   ssize_t abspath_size;
 
@@ -80,7 +81,8 @@ int uv_exepath(char* buffer, size_t* siz
 
   return 0;
 }
-#else
+#endif
+
 int uv_exepath(char* buffer, size_t* size) {
   char abspath[PATH_MAX * 2 + 1];
   int mib[4];
@@ -110,7 +112,6 @@ int uv_exepath(char* buffer, size_t* siz
 
   return 0;
 }
-#endif
 
 uint64_t uv_get_free_memory(void) {
   int freecount;
