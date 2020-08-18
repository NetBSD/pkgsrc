$NetBSD: patch-common_sysutils.c,v 1.1 2020/08/18 09:39:23 schmonz Exp $

Provide a definition of IN_EXCL_UNLINK for Linux < 2.6.36.
From https://github.com/gpg/gnupg/pull/2

--- common/sysutils.c.orig	2018-10-22 17:26:18.000000000 +0000
+++ common/sysutils.c
@@ -68,6 +68,9 @@
 #endif
 #ifdef HAVE_INOTIFY_INIT
 # include <sys/inotify.h>
+# ifndef IN_EXCL_UNLINK
+#  define IN_EXCL_UNLINK 0x04000000
+# endif
 #endif /*HAVE_INOTIFY_INIT*/
 #ifdef HAVE_NPTH
 # include <npth.h>
