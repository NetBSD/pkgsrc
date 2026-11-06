$NetBSD: patch-syscall.c,v 1.1 2026/11/06 11:52:39 wiz Exp $

https://github.com/RsyncProject/rsync/commit/ea645201fefbba7f6b6b22b621856dba3c01cdd3

--- syscall.c.orig	2026-10-26 11:16:36.000000000 +0000
+++ syscall.c
@@ -1806,6 +1806,8 @@ int do_chmod(const char *path, mode_t mode)
 				code = 1;
 # elif defined AT_FDCWD && defined AT_SYMLINK_NOFOLLOW
 			code = fchmodat(AT_FDCWD, path, mode & CHMOD_BITS, AT_SYMLINK_NOFOLLOW);
+			if (code < 0 && (errno == ENOTSUP || errno == EOPNOTSUPP || errno == ENOSYS))
+				code = 1;
 # else
 			code = 1;
 # endif
