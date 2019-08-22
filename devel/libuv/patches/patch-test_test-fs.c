$NetBSD: patch-test_test-fs.c,v 1.1 2019/08/22 10:28:25 wiz Exp $

Use statvfs on NetBSD.
https://github.com/libuv/libuv/pull/2436

--- test/test-fs.c.orig	2019-08-09 14:57:12.000000000 +0000
+++ test/test-fs.c
@@ -339,7 +339,7 @@ static void statfs_cb(uv_fs_t* req) {
   ASSERT(req->ptr != NULL);
   stats = req->ptr;
 
-#if defined(_WIN32) || defined(__sun) || defined(_AIX) || defined(__MVS__)
+#if defined(_WIN32) || defined(__sun) || defined(_AIX) || defined(__MVS__) || defined(__NetBSD__)
   ASSERT(stats->f_type == 0);
 #else
   ASSERT(stats->f_type > 0);
