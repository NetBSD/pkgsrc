$NetBSD: patch-src_gbm_main_gbm.c,v 1.2 2018/12/29 13:38:53 triaxx Exp $

* Solaris needs sys/mkdev.h for major(2).
* Linux needs sys/sysmacros.h for major(2).

--- src/gbm/main/gbm.c.orig	2016-05-01 12:48:59.000000000 +0000
+++ src/gbm/main/gbm.c
@@ -35,6 +35,11 @@
 #include <stdint.h>
 
 #include <sys/types.h>
+#ifdef __sun
+#include <sys/mkdev.h> /* for major(2) */
+#elif defined(__linux__)
+#include <sys/sysmacros.h>
+#endif
 #include <sys/stat.h>
 #include <unistd.h>
 #include <errno.h>
