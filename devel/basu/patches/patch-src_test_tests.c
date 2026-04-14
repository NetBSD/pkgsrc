$NetBSD: patch-src_test_tests.c,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* NetBSD support
* Fix logging, on NetBSD %m is only allowed in syslog(3) like function

--- src/test/tests.c.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/test/tests.c
@@ -6,7 +6,7 @@
 #include "env-util.h"
 #include "tests.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #define program_invocation_short_name getprogname()
 #endif
 
@@ -22,7 +22,7 @@ int log_tests_skipped(const char *messag
 }
 
 int log_tests_skipped_errno(int r, const char *message) {
-        log_notice_errno(r, "%s: %s, skipping tests: %m",
+        log_notice_errno(r, "%s: %s, skipping tests",
                          program_invocation_short_name, message);
         return EXIT_TEST_SKIP;
 }
