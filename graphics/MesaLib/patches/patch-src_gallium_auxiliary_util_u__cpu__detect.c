$NetBSD: patch-src_gallium_auxiliary_util_u__cpu__detect.c,v 1.1 2015/09/11 00:03:36 tnn Exp $

DragonFly support.

--- src/gallium/auxiliary/util/u_cpu_detect.c.orig	2015-07-29 21:10:43.953534000 +0000
+++ src/gallium/auxiliary/util/u_cpu_detect.c
@@ -52,7 +52,7 @@
 #include <machine/cpu.h>
 #endif
 
-#if defined(PIPE_OS_FREEBSD)
+#if defined(PIPE_OS_FREEBSD) || defined(PIPE_OS_DRAGONFLY)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
