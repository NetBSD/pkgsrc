$NetBSD: patch-test_test-fs.c,v 1.4 2023/11/07 19:55:22 adam Exp $

Apply MacPorts patch-libuv-legacy.diff for pre-10.7 platforms.

--- test/test-fs.c.orig	2023-11-06 18:17:17.000000000 +0000
+++ test/test-fs.c
@@ -1423,7 +1423,7 @@ TEST_IMPL(fs_fstat) {
   ASSERT_OK(uv_fs_fstat(NULL, &req, file, NULL));
   ASSERT_OK(req.result);
   s = req.ptr;
-# if defined(__APPLE__)
+# if defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= 1050
   ASSERT_EQ(s->st_birthtim.tv_sec, t.st_birthtimespec.tv_sec);
   ASSERT_EQ(s->st_birthtim.tv_nsec, t.st_birthtimespec.tv_nsec);
 # elif defined(__linux__)
@@ -1464,7 +1464,7 @@ TEST_IMPL(fs_fstat) {
   ASSERT_EQ(s->st_size, (uint64_t) t.st_size);
   ASSERT_EQ(s->st_blksize, (uint64_t) t.st_blksize);
   ASSERT_EQ(s->st_blocks, (uint64_t) t.st_blocks);
-#if defined(__APPLE__)
+#if defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ >= 1050
   ASSERT_EQ(s->st_atim.tv_sec, t.st_atimespec.tv_sec);
   ASSERT_EQ(s->st_atim.tv_nsec, t.st_atimespec.tv_nsec);
   ASSERT_EQ(s->st_mtim.tv_sec, t.st_mtimespec.tv_sec);
