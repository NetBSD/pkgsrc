$NetBSD: patch-libavutil_x86_cpu.c,v 1.1 2022/01/31 23:16:41 ryoon Exp $

Make a part of the code depend on GCC >= 4.2.

--- libavutil/x86/cpu.c.orig	2016-01-15 16:58:37.000000000 +0000
+++ libavutil/x86/cpu.c
@@ -116,6 +116,7 @@ int ff_get_cpu_flags_x86(void)
 #if HAVE_SSE
         if (std_caps & (1 << 25))
             rval |= AV_CPU_FLAG_SSE;
+#if !defined(__GNUC__) || (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2))
         if (std_caps & (1 << 26))
             rval |= AV_CPU_FLAG_SSE2;
         if (ecx & 1)
@@ -138,6 +139,7 @@ int ff_get_cpu_flags_x86(void)
             }
         }
 #endif /* HAVE_AVX */
+#endif /* gcc >= 4.2 */
 #endif /* HAVE_SSE */
     }
     if (max_std_level >= 7) {
