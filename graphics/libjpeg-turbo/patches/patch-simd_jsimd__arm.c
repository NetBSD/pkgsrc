$NetBSD: patch-simd_jsimd__arm.c,v 1.1 2015/07/21 21:37:12 rjs Exp $

--- simd/jsimd_arm.c.orig	2014-08-23 15:47:51.000000000 +0000
+++ simd/jsimd_arm.c
@@ -25,6 +25,10 @@
 #include <string.h>
 #include <ctype.h>
 
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
+
 static unsigned int simd_support = ~0;
 
 #if defined(__linux__) || defined(ANDROID) || defined(__ANDROID__)
@@ -100,6 +104,9 @@ init_simd (void)
   char *env = NULL;
 #if !defined(__ARM_NEON__) && defined(__linux__) || defined(ANDROID) || defined(__ANDROID__)
   int bufsize = 1024; /* an initial guess for the line buffer size limit */
+#elif defined(__NetBSD__)
+  int neon_present;
+  size_t len;
 #endif
 
   if (simd_support != ~0U)
@@ -118,6 +125,10 @@ init_simd (void)
     if (bufsize > SOMEWHAT_SANE_PROC_CPUINFO_SIZE_LIMIT)
       break;
   }
+#elif defined(__NetBSD__)
+  if (sysctlbyname("machdep.neon_present", &neon_present, &len, NULL, 0) == 0
+	&& neon_present != 0)
+    simd_support |= JSIMD_ARM_NEON;
 #endif
 
   /* Force different settings through environment variables */
