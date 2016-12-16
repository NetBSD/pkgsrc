$NetBSD: patch-g13_sh-dmcrypt.c,v 1.1 2016/12/16 16:21:54 hans Exp $

--- g13/sh-dmcrypt.c.orig	2016-05-04 11:43:16.000000000 +0200
+++ g13/sh-dmcrypt.c	2016-07-26 11:24:35.449662123 +0200
@@ -25,6 +25,9 @@
 #include <errno.h>
 #include <assert.h>
 #include <sys/types.h>
+#ifdef __sun
+#include <sys/mkdev.h>
+#endif
 #ifdef HAVE_STAT
 # include <sys/stat.h>
 #endif
