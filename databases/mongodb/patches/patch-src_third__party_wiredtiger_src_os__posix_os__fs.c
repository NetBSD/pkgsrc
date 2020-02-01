$NetBSD: patch-src_third__party_wiredtiger_src_os__posix_os__fs.c,v 1.1 2020/02/01 20:01:16 adam Exp $

On NetBSD, fdatasync() fails with "Bad file descriptor".

--- src/third_party/wiredtiger/src/os_posix/os_fs.c.orig	2020-01-29 21:12:06.697276371 +0000
+++ src/third_party/wiredtiger/src/os_posix/os_fs.c
@@ -91,7 +91,7 @@ __posix_sync(WT_SESSION_IMPL *session, i
         WT_PANIC_RET(session, ret, "%s: %s: fcntl(F_FULLFSYNC)", name, func);
     }
 #endif
-#if defined(HAVE_FDATASYNC)
+#if defined(HAVE_FDATASYNC) && !defined(__NetBSD__)
     /* See comment in __posix_sync(): sync cannot be retried or fail. */
     WT_SYSCALL(fdatasync(fd), ret);
     if (ret == 0)
