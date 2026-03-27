$NetBSD: patch-simd_arm__aarch32_jsimd.c,v 1.4 2026/03/27 10:48:22 adam Exp $

NetBSD support.

--- simd/arm/aarch32/jsimd.c.orig	2026-03-26 19:34:19.000000000 +0000
+++ simd/arm/aarch32/jsimd.c
@@ -25,6 +25,9 @@
 #include "../../jsimd.h"
 
 #include <ctype.h>
+#if defined(__NetBSD__)
+#include <sys/sysctl.h>
+#endif
 
 #if !defined(__ARM_NEON__) && \
     (defined(HAVE_GETAUXVAL) || defined(HAVE_ELF_AUX_INFO))
@@ -113,6 +116,9 @@ init_simd(void)
   unsigned long cpufeatures = 0;
 #elif defined(__linux__) || defined(ANDROID) || defined(__ANDROID__)
   int bufsize = 1024; /* an initial guess for the line buffer size limit */
+#elif defined(__NetBSD__)
+  int neon_present;
+  size_t len;
 #endif
 #endif
 
@@ -136,6 +142,10 @@ init_simd(void)
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
