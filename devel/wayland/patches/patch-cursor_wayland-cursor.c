$NetBSD: patch-cursor_wayland-cursor.c,v 1.1 2019/09/09 20:08:29 nia Exp $

fallocate is currently a no-op on NetBSD.

--- cursor/wayland-cursor.c.orig	2019-03-21 00:55:25.000000000 +0000
+++ cursor/wayland-cursor.c
@@ -86,7 +86,7 @@ shm_pool_resize(struct shm_pool *pool, i
 	if (ftruncate(pool->fd, size) < 0)
 		return 0;
 
-#ifdef HAVE_POSIX_FALLOCATE
+#if defined(HAVE_POSIX_FALLOCATE) && !defined(__NetBSD__)
 	errno = posix_fallocate(pool->fd, 0, size);
 	if (errno != 0)
 		return 0;
