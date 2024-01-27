$NetBSD: patch-libavutil_ppc_cpu.c,v 1.1 2024/01/27 02:52:50 riastradh Exp $

Handle machdep.altivec on NetBSD like on OpenBSD.

--- libavutil/ppc/cpu.c.orig	2022-05-14 21:21:50.000000000 +0000
+++ libavutil/ppc/cpu.c
@@ -27,7 +27,7 @@
 #if HAVE_UNISTD_H
 #include <unistd.h>
 #endif
-#elif defined(__OpenBSD__)
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <machine/cpu.h>
@@ -56,8 +56,8 @@ int ff_get_cpu_flags_ppc(void)
     if (result == VECTORTYPE_ALTIVEC)
         return AV_CPU_FLAG_ALTIVEC;
     return 0;
-#elif defined(__APPLE__) || defined(__OpenBSD__)
-#ifdef __OpenBSD__
+#elif defined(__APPLE__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
     int sels[2] = {CTL_MACHDEP, CPU_ALTIVEC};
 #else
     int sels[2] = {CTL_HW, HW_VECTORUNIT};
