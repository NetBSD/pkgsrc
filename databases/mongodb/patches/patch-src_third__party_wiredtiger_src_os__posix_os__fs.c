$NetBSD: patch-src_third__party_wiredtiger_src_os__posix_os__fs.c,v 1.3 2023/07/29 11:45:43 adam Exp $

The fdatasync call is specified by POSIX, and the definition has changed:
  https://pubs.opengroup.org/onlinepubs/009695399/functions/fdatasync.html
  https://pubs.opengroup.org/onlinepubs/9699919799/functions/fdatasync.html  

NetBSD's fdatasync follows the earlier specification.  For now, simply avoid
crashing on EBADF, at the possible expense of sync safety.

\todo Change NetBSD to follow the current standard.

--- src/third_party/wiredtiger/src/os_posix/os_fs.c.orig	2023-06-29 13:37:52.000000000 +0000
+++ src/third_party/wiredtiger/src/os_posix/os_fs.c
@@ -89,7 +89,7 @@ __posix_sync(WT_SESSION_IMPL *session, i
 #if defined(HAVE_FDATASYNC)
     /* See comment in __posix_sync(): sync cannot be retried or fail. */
     WT_SYSCALL(fdatasync(fd), ret);
-    if (ret == 0)
+    if (ret == 0 || errno == EBADF)
         return (0);
     WT_RET_PANIC(session, ret, "%s: %s: fdatasync", name, func);
 #else
