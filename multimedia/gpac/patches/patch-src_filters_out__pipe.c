$NetBSD: patch-src_filters_out__pipe.c,v 1.1 2025/10/31 21:46:23 adam Exp $

Fix build on NetBSD: mkfifo() definition.

--- src/filters/out_pipe.c.orig	2025-10-31 21:36:26.396230916 +0000
+++ src/filters/out_pipe.c
@@ -38,10 +38,8 @@
 #include <fcntl.h>
 #include <unistd.h>
 
-#if defined(GPAC_CONFIG_LINUX) || defined(GPAC_CONFIG_EMSCRIPTEN)
 #include <sys/types.h>
 #include <sys/stat.h>
-#endif
 
 #ifndef __BEOS__
 #include <errno.h>
