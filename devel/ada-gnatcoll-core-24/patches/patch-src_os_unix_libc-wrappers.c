$NetBSD: patch-src_os_unix_libc-wrappers.c,v 1.1 2025/07/10 12:35:22 dkazankov Exp $

Fix linker version warning on NetBSD
Add NetBSD support

--- src/os/unix/libc-wrappers.c.orig	2023-09-21 18:57:14.000000000 +0300
+++ src/os/unix/libc-wrappers.c
@@ -339,6 +339,13 @@
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
@@ -348,7 +355,7 @@
   if (result != NULL)
   {
      buf->inode = (uint_64) result->d_ino;
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
      buf->offset = 0;
 #else
      buf->offset = (uint_64) result->d_off;
