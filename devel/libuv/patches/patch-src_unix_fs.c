$NetBSD: patch-src_unix_fs.c,v 1.6 2022/01/28 21:13:10 schmonz Exp $

Fix portability on NetBSD.
Apply MacPorts patch-libuv-legacy.diff for pre-10.7 platforms.

--- src/unix/fs.c.orig	2022-01-04 14:18:00.000000000 +0000
+++ src/unix/fs.c
@@ -1060,7 +1060,7 @@ static ssize_t uv__fs_sendfile(uv_fs_t* 
 
     return -1;
   }
-#elif defined(__APPLE__)           || \
+#elif (defined(__APPLE__) && MAC_OS_X_VERSION_MAX_ALLOWED >= 1050) || \
       defined(__DragonFly__)       || \
       defined(__FreeBSD__)         || \
       defined(__FreeBSD_kernel__)
@@ -1427,7 +1427,7 @@ static void uv__to_stat(struct stat* src
   dst->st_blksize = src->st_blksize;
   dst->st_blocks = src->st_blocks;
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
   dst->st_atim.tv_sec = src->st_atimespec.tv_sec;
   dst->st_atim.tv_nsec = src->st_atimespec.tv_nsec;
   dst->st_mtim.tv_sec = src->st_mtimespec.tv_sec;
@@ -1454,7 +1454,6 @@ static void uv__to_stat(struct stat* src
     defined(__DragonFly__)   || \
     defined(__FreeBSD__)     || \
     defined(__OpenBSD__)     || \
-    defined(__NetBSD__)      || \
     defined(_GNU_SOURCE)     || \
     defined(_BSD_SOURCE)     || \
     defined(_SVID_SOURCE)    || \
@@ -1466,8 +1465,7 @@ static void uv__to_stat(struct stat* src
   dst->st_mtim.tv_nsec = src->st_mtim.tv_nsec;
   dst->st_ctim.tv_sec = src->st_ctim.tv_sec;
   dst->st_ctim.tv_nsec = src->st_ctim.tv_nsec;
-# if defined(__FreeBSD__)    || \
-     defined(__NetBSD__)
+# if defined(__FreeBSD__)
   dst->st_birthtim.tv_sec = src->st_birthtim.tv_sec;
   dst->st_birthtim.tv_nsec = src->st_birthtim.tv_nsec;
   dst->st_flags = src->st_flags;
