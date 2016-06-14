$NetBSD: patch-simd_jsimd__arm.c,v 1.2 2016/06/14 12:07:58 wiz Exp $

--- simd/jsimd_arm.c.orig	2016-06-07 17:33:40.000000000 +0000
+++ simd/jsimd_arm.c
@@ -26,6 +26,10 @@
 #include <string.h>
 #include <ctype.h>
 
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
+
 static unsigned int simd_support = ~0;
 static unsigned int simd_huffman = 1;
 
@@ -102,6 +106,9 @@ init_simd (void)
   char *env = NULL;
 #if !defined(__ARM_NEON__) && defined(__linux__) || defined(ANDROID) || defined(__ANDROID__)
   int bufsize = 1024; /* an initial guess for the line buffer size limit */
+#elif defined(__NetBSD__)
+  int neon_present;
+  size_t len;
 #endif
 
   if (simd_support != ~0U)
@@ -120,6 +127,10 @@ init_simd (void)
     if (bufsize > SOMEWHAT_SANE_PROC_CPUINFO_SIZE_LIMIT)
       break;
   }
+#elif defined(__NetBSD__)
+  if (sysctlbyname("machdep.neon_present", &neon_present, &len, NULL, 0) == 0
+	&& neon_present != 0)
+    simd_support |= JSIMD_ARM_NEON;
 #endif
 
   /* Force different settings through environment variables */
