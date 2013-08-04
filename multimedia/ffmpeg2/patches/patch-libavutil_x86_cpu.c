$NetBSD: patch-libavutil_x86_cpu.c,v 1.1 2013/08/04 10:29:02 adam Exp $

--- libavutil/x86/cpu.c.orig	2013-01-06 21:53:29.000000000 +0000
+++ libavutil/x86/cpu.c
@@ -115,6 +115,7 @@ int ff_get_cpu_flags_x86(void)
 #if HAVE_SSE
         if (std_caps & (1 << 25))
             rval |= AV_CPU_FLAG_SSE;
+#if !defined(__GNUC__) || (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2))
         if (std_caps & (1 << 26))
             rval |= AV_CPU_FLAG_SSE2;
         if (ecx & 1)
@@ -134,6 +135,7 @@ int ff_get_cpu_flags_x86(void)
                 rval |= AV_CPU_FLAG_AVX;
         }
 #endif /* HAVE_AVX */
+#endif /* gcc >= 4.2 */
 #endif /* HAVE_SSE */
     }
 
