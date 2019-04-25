$NetBSD: patch-Python_pylifecycle.c,v 1.2 2019/04/25 17:44:21 leot Exp $

NetBSD is also affected by bpo-30225 (<https://bugs.python.org/issue30225>),
use fstat(2) on NetBSD too.  Fixes PR pkg/53229.

Reported upstream via bpo-33384: <https://bugs.python.org/issue33384>

--- Python/pylifecycle.c.orig	2019-04-09 17:51:55.000000000 +0000
+++ Python/pylifecycle.c
@@ -1043,7 +1043,7 @@ initsite(void)
 static int
 is_valid_fd(int fd)
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__NetBSD__)
     /* bpo-30225: On macOS Tiger, when stdout is redirected to a pipe
        and the other side of the pipe is closed, dup(1) succeed, whereas
        fstat(1, &st) fails with EBADF. Prefer fstat() over dup() to detect
