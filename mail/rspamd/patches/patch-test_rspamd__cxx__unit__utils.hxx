$NetBSD: patch-test_rspamd__cxx__unit__utils.hxx,v 1.1 2026/11/16 11:40:00 wiz Exp $

https://github.com/rspamd/rspamd/commit/b9ca0d19bc01111df2cbb04cc017ee574a348c3a

--- test/rspamd_cxx_unit_utils.hxx.orig	2026-11-13 13:31:32.000000000 +0000
+++ test/rspamd_cxx_unit_utils.hxx
@@ -294,7 +294,10 @@ TEST_SUITE("rspamd_utils")
 			sigemptyset(&action.sa_mask);
 			REQUIRE(sigaction(SIGXFSZ, &action, &old_action) == 0);
 			REQUIRE(setrlimit(RLIMIT_FSIZE, &limit) == 0);
-			/* The first write stops at the limit, the next one fails with EFBIG */
+			/*
+			 * Linux writes up to the limit and fails the next write with EFBIG;
+			 * the BSDs refuse a write that crosses the limit as a whole
+			 */
 			auto ret = rspamd_write_all(fd, data.data(), data.size());
 			auto saved_errno = errno;
 			/* Restore before any doctest output, it may go to a regular file */
@@ -304,7 +307,7 @@ TEST_SUITE("rspamd_utils")
 			CHECK_FALSE(ret);
 			CHECK(saved_errno == EFBIG);
 			REQUIRE(fstat(fd, &st) == 0);
-			CHECK(st.st_size == 4);
+			CHECK(st.st_size <= 4);
 		}
 #endif
 
