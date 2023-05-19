$NetBSD: patch-src_unix_fs.c,v 1.7 2023/05/19 20:35:47 adam Exp $

Fix portability on NetBSD.
Apply MacPorts patch-libuv-legacy.diff for pre-10.7 platforms.

--- src/unix/fs.c.orig	2023-05-19 11:21:01.000000000 +0000
+++ src/unix/fs.c
@@ -1053,7 +1053,7 @@ static ssize_t uv__fs_sendfile(uv_fs_t* 
 
     return -1;
   }
-#elif defined(__APPLE__) || defined(__DragonFly__) || defined(__FreeBSD__)
+#elif (defined(__APPLE__) && MAC_OS_X_VERSION_MAX_ALLOWED >= 1050) || defined(__DragonFly__) || defined(__FreeBSD__)
   {
     off_t len;
     ssize_t r;
@@ -1431,7 +1431,7 @@ static void uv__to_stat(struct stat* src
   dst->st_blksize = src->st_blksize;
   dst->st_blocks = src->st_blocks;
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
   dst->st_atim.tv_sec = src->st_atimespec.tv_sec;
   dst->st_atim.tv_nsec = src->st_atimespec.tv_nsec;
   dst->st_mtim.tv_sec = src->st_mtimespec.tv_sec;
@@ -1458,7 +1458,6 @@ static void uv__to_stat(struct stat* src
     defined(__DragonFly__)   || \
     defined(__FreeBSD__)     || \
     defined(__OpenBSD__)     || \
-    defined(__NetBSD__)      || \
     defined(_GNU_SOURCE)     || \
     defined(_BSD_SOURCE)     || \
     defined(_SVID_SOURCE)    || \
@@ -1470,8 +1469,7 @@ static void uv__to_stat(struct stat* src
   dst->st_mtim.tv_nsec = src->st_mtim.tv_nsec;
   dst->st_ctim.tv_sec = src->st_ctim.tv_sec;
   dst->st_ctim.tv_nsec = src->st_ctim.tv_nsec;
-# if defined(__FreeBSD__)    || \
-     defined(__NetBSD__)
+# if defined(__FreeBSD__)
   dst->st_birthtim.tv_sec = src->st_birthtim.tv_sec;
   dst->st_birthtim.tv_nsec = src->st_birthtim.tv_nsec;
   dst->st_flags = src->st_flags;
