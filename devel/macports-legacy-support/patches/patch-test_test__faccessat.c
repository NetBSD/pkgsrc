$NetBSD: patch-test_test__faccessat.c,v 1.1 2023/11/15 15:23:13 nia Exp $

Fix 10.4 support.
https://github.com/macports/macports-legacy-support/pull/69

--- test/test_faccessat.c.orig	2023-09-15 08:59:52.000000000 +0000
+++ test/test_faccessat.c
@@ -351,8 +351,8 @@ int main(int ac, char **av)
 	if (check_pathname_rc == -1)
 		TEST(check_pathname_errno == EFAULT, "check pathname errno wrong (should be EFAULT)", check_pathname_errno)
 	TEST(check_dirfd_rc == -1, "check dirfd failed", 0)
-	if (check_dirfd_rc == -1)
-		TEST(check_dirfd_errno == EBADF, "check dirfd errno wrong (should be EBADF)", check_dirfd_errno)
+	if (check_dirfd_rc == -1) // On 10.14 this is EBADF. On 10.4 it's ENOENT
+		TEST(check_dirfd_errno == EBADF || check_dirfd_errno == ENOENT, "check dirfd errno wrong (should be EBADF or ENOENT)", check_dirfd_errno)
 	TEST(check_mode_rc == -1, "check mode failed", 0) // Apple doesn't check this argument - failure is ENOENT/EPERM
 	//if (check_mode_rc == -1)
 	//	TEST(check_mode_errno == EINVAL, "check mode errno wrong (should be EINVAL)", check_mode_errno)
