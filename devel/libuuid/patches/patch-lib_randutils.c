$NetBSD: patch-lib_randutils.c,v 1.2 2015/09/30 20:38:16 wiz Exp $

O_CLOEXEC is not available on every platform (e.g. MacOS X < 10.7). It
was introduced in POSIX 2008.

--- lib/randutils.c.orig	2015-04-29 07:52:21.000000000 +0000
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
