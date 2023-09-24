$NetBSD: patch-src_lib_compat.h,v 1.1 2023/09/24 18:03:09 schmonz Exp $

Apply upstream PR #211 to fix macOS build.

--- src/lib/compat.h.orig	2023-09-14 13:17:46.000000000 +0000
+++ src/lib/compat.h
@@ -110,15 +110,24 @@ typedef int socklen_t;
 #  define ST_ATIME_NSEC(st) ((unsigned long)(st).st_atim.tv_nsec)
 #  define ST_MTIME_NSEC(st) ((unsigned long)(st).st_mtim.tv_nsec)
 #  define ST_CTIME_NSEC(st) ((unsigned long)(st).st_ctim.tv_nsec)
+#  define ST_ATIME_SEC(st) ((unsigned long)(st).st_atim.tv_sec)
+#  define ST_MTIME_SEC(st) ((unsigned long)(st).st_mtim.tv_sec)
+#  define ST_CTIME_SEC(st) ((unsigned long)(st).st_ctim.tv_sec)
 #elif defined (HAVE_STAT_XTIMESPEC)
 #  define HAVE_ST_NSECS
 #  define ST_ATIME_NSEC(st) ((unsigned long)(st).st_atimespec.tv_nsec)
 #  define ST_MTIME_NSEC(st) ((unsigned long)(st).st_mtimespec.tv_nsec)
 #  define ST_CTIME_NSEC(st) ((unsigned long)(st).st_ctimespec.tv_nsec)
+#  define ST_ATIME_SEC(st) ((unsigned long)(st).st_atimespec.tv_sec)
+#  define ST_MTIME_SEC(st) ((unsigned long)(st).st_mtimespec.tv_sec)
+#  define ST_CTIME_SEC(st) ((unsigned long)(st).st_ctimespec.tv_sec)
 #else
 #  define ST_ATIME_NSEC(st) 0UL
 #  define ST_MTIME_NSEC(st) 0UL
 #  define ST_CTIME_NSEC(st) 0UL
+#  define ST_ATIME_SEC(st) 0UL
+#  define ST_MTIME_SEC(st) 0UL
+#  define ST_CTIME_SEC(st) 0UL
 #endif
 
 #ifdef HAVE_ST_NSECS
