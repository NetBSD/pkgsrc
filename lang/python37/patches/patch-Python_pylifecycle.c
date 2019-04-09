$NetBSD: patch-Python_pylifecycle.c,v 1.1 2019/04/09 18:47:25 adam Exp $

NetBSD is also affected by bpo-30225.
See bpo-33384: https://bugs.python.org/issue33384

--- Python/pylifecycle.c.orig	2019-03-25 20:21:05.000000000 +0000
+++ Python/pylifecycle.c
@@ -1672,7 +1672,7 @@ initsite(void)
 static int
 is_valid_fd(int fd)
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
     /* bpo-30225: On macOS Tiger, when stdout is redirected to a pipe
        and the other side of the pipe is closed, dup(1) succeed, whereas
        fstat(1, &st) fails with EBADF. Prefer fstat() over dup() to detect
