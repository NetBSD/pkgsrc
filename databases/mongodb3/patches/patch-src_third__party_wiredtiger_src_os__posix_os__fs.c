$NetBSD: patch-src_third__party_wiredtiger_src_os__posix_os__fs.c,v 1.2 2020/03/05 01:41:52 gdt Exp $

On NetBSD, fdatasync() fails with "Bad file descriptor".
\todo Explain if this is only for fdatasync on directories vs files.

\todo File upstream and add upstream bugtracker URL.

--- src/third_party/wiredtiger/src/os_posix/os_fs.c.orig	2020-01-08 16:30:41.000000000 +0000
+++ src/third_party/wiredtiger/src/os_posix/os_fs.c
@@ -103,7 +103,7 @@ __posix_sync(
 #if defined(HAVE_FDATASYNC)
 	/* See comment in __posix_sync(): sync cannot be retried or fail. */
 	WT_SYSCALL(fdatasync(fd), ret);
-	if (ret == 0)
+	if (ret == 0 || errno == EBADF)
 		return (0);
 	WT_PANIC_RET(session, ret, "%s: %s: fdatasync", name, func);
 #else
