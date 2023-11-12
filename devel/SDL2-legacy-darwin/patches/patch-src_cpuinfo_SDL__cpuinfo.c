$NetBSD: patch-src_cpuinfo_SDL__cpuinfo.c,v 1.1 2023/11/12 21:28:04 nia Exp $

NetBSD support.

--- src/cpuinfo/SDL_cpuinfo.c.orig	2014-03-16 02:31:44.000000000 +0000
+++ src/cpuinfo/SDL_cpuinfo.c
@@ -665,7 +665,9 @@ SDL_GetSystemRAM(void)
 #endif
 #ifdef HAVE_SYSCTLBYNAME
         if (SDL_SystemRAM <= 0) {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#ifdef HW_PHYSMEM64
+            int mib[2] = {CTL_HW, HW_PHYSMEM64};
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 #ifdef HW_REALMEM
             int mib[2] = {CTL_HW, HW_REALMEM};
 #else
