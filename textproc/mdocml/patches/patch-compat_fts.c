$NetBSD: patch-compat_fts.c,v 1.5 2015/03/26 19:59:53 sevan Exp $

Fix build under Solaris 10.

--- compat_fts.c.orig	2015-03-13 12:38:38.000000000 +0000
+++ compat_fts.c	2015-03-19 08:22:11.000000000 +0000
@@ -76,6 +76,10 @@
 
 #define	FCHDIR(sp, fd)	(!ISSET(FTS_NOCHDIR) && fchdir(fd))
 
+#ifdef __sun__
+#define dirfd(fd) ((fd)->dd_fd)
+#endif
+
 FTS *
 fts_open(char * const *argv, int options, void *dummy)
 {
