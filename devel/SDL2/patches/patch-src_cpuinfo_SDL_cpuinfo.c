$NetBSD: patch-src_cpuinfo_SDL_cpuinfo.c,v 1.1 2013/11/02 20:20:07 adam Exp $

Fix building on NetBSD and OpenBSD.

--- src/cpuinfo/SDL_cpuinfo.c.orig	2013-11-02 19:57:32.000000000 +0000
+++ src/cpuinfo/SDL_cpuinfo.c
@@ -621,7 +621,7 @@ SDL_GetSystemRAM(void)
 #endif
 #ifdef HAVE_SYSCTLBYNAME
         if (SDL_SystemRAM <= 0) {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #ifdef HW_REALMEM
             int mib[2] = {CTL_HW, HW_REALMEM};
 #else
