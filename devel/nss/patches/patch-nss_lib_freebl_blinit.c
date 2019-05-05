$NetBSD: patch-nss_lib_freebl_blinit.c,v 1.3 2019/05/05 22:47:28 ryoon Exp $

* Fix for arm/aarch64

--- nss/lib/freebl/blinit.c.orig	2018-04-09 15:38:16.000000000 +0000
+++ nss/lib/freebl/blinit.c	2018-04-12 14:29:56.040326263 +0000
@@ -92,7 +92,7 @@
 #endif /* NSS_X86_OR_X64 */
 
 /* clang-format off */
-#if (defined(__aarch64__) || defined(__arm__)) && !defined(__ANDROID__)
+#if (defined(__aarch64__) || defined(__arm__)) && defined(__linux__)
 #ifndef __has_include
 #define __has_include(x) 0
 #endif
@@ -105,10 +105,10 @@
 #define AT_HWCAP2 0
 #define AT_HWCAP 0
 #endif /* defined(__GNUC__) && __GNUC__ >= 2 && defined(__ELF__)*/
-#endif /* (defined(__aarch64__) || defined(__arm__)) && !defined(__ANDROID__) */
+#endif /* (defined(__aarch64__) || defined(__arm__)) && defined(__linux__) */
 /* clang-format on */
 
-#if defined(__aarch64__) && !defined(__ANDROID__)
+#if defined(__aarch64__) && defined(__linux__)
 // Defines from hwcap.h in Linux kernel - ARM64
 #ifndef HWCAP_AES
 #define HWCAP_AES (1 << 3)
@@ -138,9 +138,9 @@
     /* aarch64 must support NEON. */
     arm_neon_support_ = disable_arm_neon == NULL;
 }
-#endif /* defined(__aarch64__) && !defined(__ANDROID__) */
+#endif /* defined(__aarch64__) && defined(__linux__) */
 
-#if defined(__arm__) && !defined(__ANDROID__)
+#if defined(__arm__) && defined(__linux__)
 // Defines from hwcap.h in Linux kernel - ARM
 /*
  * HWCAP flags - for elf_hwcap (in kernel) and AT_HWCAP
@@ -179,7 +179,7 @@
         arm_neon_support_ = hwcaps & HWCAP_NEON && disable_arm_neon == NULL;
     }
 }
-#endif /* defined(__arm__) && !defined(__ANDROID__) */
+#endif /* defined(__arm__) && defined(__linux__) */
 
 // Enable when Firefox can use it.
 // #if defined(__ANDROID__) && (defined(__arm__) || defined(__aarch64__))
@@ -262,7 +262,7 @@
 {
 #ifdef NSS_X86_OR_X64
     CheckX86CPUSupport();
-#elif (defined(__aarch64__) || defined(__arm__)) && !defined(__ANDROID__)
+#elif (defined(__aarch64__) || defined(__arm__)) && defined(__linux__)
     CheckARMSupport();
 #endif
     return PR_SUCCESS;
