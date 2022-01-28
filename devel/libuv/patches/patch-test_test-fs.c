$NetBSD: patch-test_test-fs.c,v 1.3 2022/01/28 21:13:10 schmonz Exp $

Apply MacPorts patch-libuv-legacy.diff for pre-10.7 platforms.

--- test/test-fs.c.orig	2022-01-04 14:18:00.000000000 +0000
+++ test/test-fs.c
@@ -1405,7 +1405,7 @@ TEST_IMPL(fs_fstat) {
   ASSERT(0 == uv_fs_fstat(NULL, &req, file, NULL));
   ASSERT(req.result == 0);
   s = req.ptr;
-# if defined(__APPLE__)
+# if defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= 1050
   ASSERT(s->st_birthtim.tv_sec == t.st_birthtimespec.tv_sec);
   ASSERT(s->st_birthtim.tv_nsec == t.st_birthtimespec.tv_nsec);
 # elif defined(__linux__)
@@ -1446,7 +1446,7 @@ TEST_IMPL(fs_fstat) {
   ASSERT(s->st_size == (uint64_t) t.st_size);
   ASSERT(s->st_blksize == (uint64_t) t.st_blksize);
   ASSERT(s->st_blocks == (uint64_t) t.st_blocks);
-#if defined(__APPLE__)
+#if defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= 1050
   ASSERT(s->st_atim.tv_sec == t.st_atimespec.tv_sec);
   ASSERT(s->st_atim.tv_nsec == t.st_atimespec.tv_nsec);
   ASSERT(s->st_mtim.tv_sec == t.st_mtimespec.tv_sec);
