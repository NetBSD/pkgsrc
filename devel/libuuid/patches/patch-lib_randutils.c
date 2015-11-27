$NetBSD: patch-lib_randutils.c,v 1.4 2015/11/27 14:57:36 jperkin Exp $

O_CLOEXEC is not available on every platform (e.g. MacOS X < 10.7). It
was introduced in POSIX 2008.

--- lib/randutils.c.orig	2015-10-05 14:18:43.000000000 +0000
+++ lib/randutils.c
@@ -30,6 +30,10 @@
 THREAD_LOCAL unsigned short ul_jrand_seed[3];
 #endif
 
+#if !defined(O_CLOEXEC)
+#define O_CLOEXEC 0
+#endif
+
 int random_get_fd(void)
 {
 	int i, fd;
