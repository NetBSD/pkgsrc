$NetBSD: patch-simd_arm__aarch64_jsimd.c,v 1.1 2021/04/26 08:18:48 adam Exp $

--- simd/arm/aarch64/jsimd.c.orig	2021-04-23 16:42:40.000000000 +0000
+++ simd/arm/aarch64/jsimd.c
@@ -33,6 +33,10 @@
 #define JSIMD_FASTST3  2
 #define JSIMD_FASTTBL  4
 
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
+
 static unsigned int simd_support = ~0;
 static unsigned int simd_huffman = 1;
 static unsigned int simd_features = JSIMD_FASTLD3 | JSIMD_FASTST3 |
@@ -129,6 +133,9 @@ init_simd(void)
 #endif
 #if defined(__linux__) || defined(ANDROID) || defined(__ANDROID__)
   int bufsize = 1024; /* an initial guess for the line buffer size limit */
+#elif defined(__NetBSD__)
+  int neon_present;
+  size_t len;
 #endif
 
   if (simd_support != ~0U)
@@ -143,6 +150,10 @@ init_simd(void)
     if (bufsize > SOMEWHAT_SANE_PROC_CPUINFO_SIZE_LIMIT)
       break;
   }
+#elif defined(__NetBSD__)
+  if (sysctlbyname("machdep.neon_present", &neon_present, &len, NULL, 0) == 0
+	&& neon_present != 0)
+    simd_support |= JSIMD_NEON;
 #endif
 
 #ifndef NO_GETENV
