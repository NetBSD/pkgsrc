$NetBSD: patch-babl_babl-cpuaccel.c,v 1.1 2022/03/23 22:43:43 tnn Exp $

only use Linux-specific neon instruction set detection on Linux

--- babl/babl-cpuaccel.c.orig	2022-02-21 21:30:17.000000000 +0000
+++ babl/babl-cpuaccel.c
@@ -550,7 +550,7 @@ arch_accel (void)
 
 #endif /* ARCH_PPC && USE_ALTIVEC */
 
-#if defined(ARCH_ARM)
+#if defined(ARCH_ARM) && defined(__linux__)
 
 #include <unistd.h>
 #include <fcntl.h>
