$NetBSD: patch-src_third__party_wiredtiger_src_os__posix_os__fs.c,v 1.1 2020/02/01 20:05:54 adam Exp $

On NetBSD, fdatasync() fails with "Bad file descriptor".

--- src/third_party/wiredtiger/src/os_posix/os_fs.c.orig	2020-01-08 16:30:41.000000000 +0000
+++ src/third_party/wiredtiger/src/os_posix/os_fs.c
@@ -100,7 +100,7 @@ __posix_sync(
 		    ret, "%s: %s: fcntl(F_FULLFSYNC)", name, func);
 	}
 #endif
-#if defined(HAVE_FDATASYNC)
+#if defined(HAVE_FDATASYNC) && !defined(__NetBSD__)
 	/* See comment in __posix_sync(): sync cannot be retried or fail. */
 	WT_SYSCALL(fdatasync(fd), ret);
 	if (ret == 0)
