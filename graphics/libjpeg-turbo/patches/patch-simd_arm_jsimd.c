$NetBSD: patch-simd_arm_jsimd.c,v 1.1 2020/04/12 06:17:06 adam Exp $

--- simd/arm/jsimd.c.orig	2019-12-31 07:10:30.000000000 +0000
+++ simd/arm/jsimd.c
@@ -28,6 +28,10 @@
 #include <string.h>
 #include <ctype.h>
 
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
+
 static unsigned int simd_support = ~0;
 static unsigned int simd_huffman = 1;
 
@@ -108,6 +112,9 @@ init_simd(void)
 #endif
 #if !defined(__ARM_NEON__) && (defined(__linux__) || defined(ANDROID) || defined(__ANDROID__))
   int bufsize = 1024; /* an initial guess for the line buffer size limit */
+#elif defined(__NetBSD__)
+  int neon_present;
+  size_t len;
 #endif
 
   if (simd_support != ~0U)
@@ -126,6 +133,10 @@ init_simd(void)
     if (bufsize > SOMEWHAT_SANE_PROC_CPUINFO_SIZE_LIMIT)
       break;
   }
+#elif defined(__NetBSD__)
+  if (sysctlbyname("machdep.neon_present", &neon_present, &len, NULL, 0) == 0
+	&& neon_present != 0)
+    simd_support |= JSIMD_ARM_NEON;
 #endif
 
 #ifndef NO_GETENV
