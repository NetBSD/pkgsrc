$NetBSD: patch-src_third__party_wiredtiger_src_os__posix_os__fs.c,v 1.3 2020/03/06 14:22:46 gdt Exp $

Without this patch, the WT_PANIC_RET message happens, with errno EBADF.
The fdatasync() function is specified to fail if fd is not a valid file
descriptor that is open for writing.  We believe that it is being called
on a directory, which is therefore invalid.  On Linux, one can use
fdatasync() on non-writable file descriptors, but the Linux man page
acknowledges that this is non-standard behavior.

To work around this upstream bug, silently ignore fdatasync errno values
of EBADF.  A better fix is likely to use fsync on directories instead.

\todo Explore the fsync instead approach.

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
