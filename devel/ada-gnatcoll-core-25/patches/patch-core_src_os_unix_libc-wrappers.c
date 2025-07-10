$NetBSD: patch-core_src_os_unix_libc-wrappers.c,v 1.1 2025/07/10 18:52:41 dkazankov Exp $

Fix linker version warning on NetBSD
Add NetBSD support

--- core/src/os/unix/libc-wrappers.c.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/src/os/unix/libc-wrappers.c
@@ -400,6 +400,13 @@
   char name[GNATCOLL_DIRENT_NAME_MAX];
 };
 
+#if defined(__NetBSD__)
+DIR * __gnatcoll_opendir(const char *filename)
+{
+    return opendir(filename);
+}
+#endif
+
 void __gnatcoll_readdir(DIR *dirp, struct gnatcoll_dirent *buf)
 {
   struct dirent *result;
@@ -409,7 +416,7 @@
   if (result != NULL)
   {
      buf->inode = (uint_64) result->d_ino;
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
      buf->offset = 0;
 #else
      buf->offset = (uint_64) result->d_off;
