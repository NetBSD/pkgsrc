$NetBSD: patch-src_lib_test-file-cache.c,v 1.1 2021/01/09 11:23:19 schmonz Exp $

Add missing ifdef guard to fix OpenBSD build.

--- src/lib/test-file-cache.c.orig	Tue Dec 22 13:26:52 2020
+++ src/lib/test-file-cache.c
@@ -254,6 +254,7 @@ static void test_file_cache_errors(void)
 	test_assert(size == 0);
 	test_assert(map == NULL);
 
+#ifdef HAVE_RLIMIT_AS
 	/* temporarily set a small memory limit to make mmap attempt fail */
 	struct rlimit rl_cur;
 	test_assert(getrlimit(RLIMIT_AS, &rl_cur) == 0);
@@ -277,6 +278,7 @@ static void test_file_cache_errors(void)
 	test_expect_error_string(errstr);
 	test_assert(file_cache_set_size(cache, page_size*2) == -1);
 	test_assert(setrlimit(RLIMIT_AS, &rl_cur) == 0);
+#endif
 
 	file_cache_free(&cache);
 	i_close_fd(&fd);
