$NetBSD: patch-gegl_gegl-cpuaccel.c,v 1.1 2022/03/24 00:02:25 tnn Exp $

only use Linux-specific neon instruction set detection on Linux

--- gegl/gegl-cpuaccel.c.orig	2022-02-21 22:29:17.000000000 +0000
+++ gegl/gegl-cpuaccel.c
@@ -546,7 +546,7 @@ arch_accel (void)
 #endif /* ARCH_PPC && USE_ALTIVEC */
 
 
-#if defined(ARCH_ARM)
+#if defined(ARCH_ARM) && defined(__linux__)
 
 #include <unistd.h>
 #include <fcntl.h>
