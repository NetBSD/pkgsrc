$NetBSD: patch-cursor_os-compatibility.c,v 1.1 2019/08/19 12:50:23 nia Exp $

fallocate is currently a no-op on NetBSD.
Make sure ftruncate is used instead.

--- cursor/os-compatibility.c.orig	2019-03-21 00:55:25.000000000 +0000
+++ cursor/os-compatibility.c
@@ -129,7 +129,7 @@ os_create_anonymous_file(off_t size)
 	if (fd < 0)
 		return -1;
 
-#ifdef HAVE_POSIX_FALLOCATE
+#if defined(HAVE_POSIX_FALLOCATE) && !defined(__NetBSD__)
 	ret = posix_fallocate(fd, 0, size);
 	if (ret != 0) {
 		close(fd);
