$NetBSD: patch-src_third__party_wiredtiger_src_os__posix_os__fs.c,v 1.5 2020/03/31 14:34:41 gdt Exp $

The fdatasync call is specified by POSIX, and the definition has changed:
  https://pubs.opengroup.org/onlinepubs/009695399/functions/fdatasync.html
  https://pubs.opengroup.org/onlinepubs/9699919799/functions/fdatasync.html  

NetBSD's fdatasync followed the earlier specification.  Current has been
updated, with pullups expected.  However, it will be a long time until
all NetBSD systems can be presumed to have the fix.  For now, simply
avoid crashing on EBADF, at the possible expense of sync safety.

Not filed upstream, because this is working around a NetBSD bug and
upstream would close it due to 3.4 being EOL anyway.

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
