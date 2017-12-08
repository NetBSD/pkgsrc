$NetBSD: patch-lib_randutils.c,v 1.5 2017/12/08 08:03:35 adam Exp $

O_CLOEXEC is not available on every platform (e.g. MacOS X < 10.7). It
was introduced in POSIX 2008.

--- lib/randutils.c.orig	2017-10-02 09:30:08.000000000 +0000
+++ lib/randutils.c
@@ -72,6 +72,10 @@ static void crank_random(void)
 		rand();
 }
 
+#if !defined(O_CLOEXEC)
+#define O_CLOEXEC 0
+#endif
+
 int random_get_fd(void)
 {
 	int i, fd;
