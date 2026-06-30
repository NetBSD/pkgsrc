$NetBSD: patch-simd_arm__aarch32_jsimdcpu.c,v 1.1 2026/06/30 20:07:32 adam Exp $

NetBSD support.

--- simd/arm/aarch32/jsimdcpu.c.orig	2026-06-30 17:25:43.000000000 +0000
+++ simd/arm/aarch32/jsimdcpu.c
@@ -27,6 +27,9 @@
 #include "../../jsimdint.h"
 
 #include <ctype.h>
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
 
 #if !defined(__ARM_NEON__) && \
     (defined(HAVE_GETAUXVAL) || defined(HAVE_ELF_AUX_INFO))
@@ -108,6 +111,9 @@ jpeg_simd_cpu_support(void)
   unsigned long cpufeatures = 0;
 #elif defined(__linux__) || defined(ANDROID) || defined(__ANDROID__)
   int bufsize = 1024; /* an initial guess for the line buffer size limit */
+#elif defined(__NetBSD__)
+  int neon_present;
+  size_t len;
 #endif
 #endif
   unsigned int simd_support = 0;
@@ -127,6 +133,10 @@ jpeg_simd_cpu_support(void)
     if (bufsize > SOMEWHAT_SANE_PROC_CPUINFO_SIZE_LIMIT)
       break;
   }
+#elif defined(__NetBSD__)
+  if (sysctlbyname("machdep.neon_present", &neon_present, &len, NULL, 0) == 0
+	&& neon_present != 0)
+    simd_support |= JSIMD_NEON;
 #elif defined(HAVE_ELF_AUX_INFO)
   elf_aux_info(AT_HWCAP, &cpufeatures, sizeof(cpufeatures));
   if (cpufeatures & HWCAP_NEON)
