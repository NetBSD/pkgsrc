$NetBSD: patch-src_gbm_main_gbm.c,v 1.1 2015/04/25 11:19:18 tnn Exp $

Solaris needs sys/mkdev.h for major(2).

--- src/gbm/main/gbm.c.orig	2015-03-21 00:51:18.000000000 +0000
+++ src/gbm/main/gbm.c
@@ -35,6 +35,9 @@
 #include <stdint.h>
 
 #include <sys/types.h>
+#ifdef __sun
+#include <sys/mkdev.h> /* for major(2) */
+#endif
 #include <sys/stat.h>
 #include <unistd.h>
 #include <errno.h>
