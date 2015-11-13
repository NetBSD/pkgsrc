$NetBSD: patch-src_cpuinfo_SDL_cpuinfo.c,v 1.3 2015/11/13 14:13:26 wiz Exp $

Fix building on NetBSD and OpenBSD.
NetBSD part submitted as
https://bugzilla.libsdl.org/show_bug.cgi?id=3176

--- src/cpuinfo/SDL_cpuinfo.c.orig	2014-03-08 04:36:51.000000000 +0000
+++ src/cpuinfo/SDL_cpuinfo.c
@@ -665,7 +665,7 @@ SDL_GetSystemRAM(void)
 #endif
 #ifdef HAVE_SYSCTLBYNAME
         if (SDL_SystemRAM <= 0) {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #ifdef HW_REALMEM
             int mib[2] = {CTL_HW, HW_REALMEM};
 #else
