$NetBSD: patch-src_unix_fs.c,v 1.2 2019/08/16 12:06:31 wiz Exp $

* Fix portability on NetBSD.

--- src/unix/fs.c.orig	2019-08-09 14:57:12.000000000 +0000
+++ src/unix/fs.c
@@ -537,7 +537,7 @@ static int uv__fs_closedir(uv_fs_t* req)
 
 static int uv__fs_statfs(uv_fs_t* req) {
   uv_statfs_t* stat_fs;
-#if defined(__sun) || defined(__MVS__)
+#if defined(__sun) || defined(__MVS__) || defined(__NetBSD__)
   struct statvfs buf;
 
   if (0 != statvfs(req->path, &buf))
@@ -554,7 +554,7 @@ static int uv__fs_statfs(uv_fs_t* req) {
     return -1;
   }
 
-#if defined(__sun) || defined(__MVS__)
+#if defined(__sun) || defined(__MVS__) || defined(__NetBSD__)
   stat_fs->f_type = 0;  /* f_type is not supported. */
 #else
   stat_fs->f_type = buf.f_type;
@@ -1147,7 +1147,7 @@ static void uv__to_stat(struct stat* src
   dst->st_blksize = src->st_blksize;
   dst->st_blocks = src->st_blocks;
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
   dst->st_atim.tv_sec = src->st_atimespec.tv_sec;
   dst->st_atim.tv_nsec = src->st_atimespec.tv_nsec;
   dst->st_mtim.tv_sec = src->st_mtimespec.tv_sec;
@@ -1173,7 +1173,6 @@ static void uv__to_stat(struct stat* src
     defined(__DragonFly__)   || \
     defined(__FreeBSD__)     || \
     defined(__OpenBSD__)     || \
-    defined(__NetBSD__)      || \
     defined(_GNU_SOURCE)     || \
     defined(_BSD_SOURCE)     || \
     defined(_SVID_SOURCE)    || \
@@ -1185,8 +1184,7 @@ static void uv__to_stat(struct stat* src
   dst->st_mtim.tv_nsec = src->st_mtim.tv_nsec;
   dst->st_ctim.tv_sec = src->st_ctim.tv_sec;
   dst->st_ctim.tv_nsec = src->st_ctim.tv_nsec;
-# if defined(__FreeBSD__)    || \
-     defined(__NetBSD__)
+# if defined(__FreeBSD__)
   dst->st_birthtim.tv_sec = src->st_birthtim.tv_sec;
   dst->st_birthtim.tv_nsec = src->st_birthtim.tv_nsec;
   dst->st_flags = src->st_flags;
