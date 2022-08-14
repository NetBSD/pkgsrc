$NetBSD: patch-simd_arm__aarch32_jsimd.c,v 1.2 2022/08/14 20:57:40 adam Exp $

--- simd/arm/aarch32/jsimd.c.orig	2022-08-08 21:03:55.000000000 +0000
+++ simd/arm/aarch32/jsimd.c
@@ -27,6 +27,10 @@
 
 #include <ctype.h>
 
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
+
 static unsigned int simd_support = ~0;
 static unsigned int simd_huffman = 1;
 
@@ -107,6 +111,9 @@ init_simd(void)
 #endif
 #if !defined(__ARM_NEON__) && (defined(__linux__) || defined(ANDROID) || defined(__ANDROID__))
   int bufsize = 1024; /* an initial guess for the line buffer size limit */
+#elif defined(__NetBSD__)
+  int neon_present;
+  size_t len;
 #endif
 
   if (simd_support != ~0U)
@@ -125,6 +132,10 @@ init_simd(void)
     if (bufsize > SOMEWHAT_SANE_PROC_CPUINFO_SIZE_LIMIT)
       break;
   }
+#elif defined(__NetBSD__)
+  if (sysctlbyname("machdep.neon_present", &neon_present, &len, NULL, 0) == 0
+	&& neon_present != 0)
+    simd_support |= JSIMD_NEON;
 #endif
 
 #ifndef NO_GETENV
