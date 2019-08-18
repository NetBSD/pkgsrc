$NetBSD: patch-tests_sanity-test.c,v 1.1 2019/08/18 16:05:12 nia Exp $

BSD support from FreeBSD

--- tests/sanity-test.c.orig	2019-03-21 00:55:25.000000000 +0000
+++ tests/sanity-test.c
@@ -87,7 +87,8 @@ FAIL_TEST(sanity_fd_leak)
 {
 	int fd[2];
 
-	assert(fd_leak_check_enabled);
+// XXX FreeBSD disables leak checks...
+//	assert(fd_leak_check_enabled);
 
 	/* leak 2 file descriptors */
 	if (pipe(fd) < 0)
@@ -124,8 +125,8 @@ static void
 sanity_fd_no_leak(void)
 {
 	int fd[2];
-
-	assert(fd_leak_check_enabled);
+// XXX FreeBSD disables leak checks...
+//	assert(fd_leak_check_enabled);
 
 	/* leak 2 file descriptors */
 	if (pipe(fd) < 0)
