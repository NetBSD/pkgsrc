$NetBSD: patch-nss_lib_freebl_blinit.c,v 1.1 2018/04/12 10:37:11 bouyer Exp $

--- ./nss/lib/freebl/blinit.c.orig	2018-04-10 17:16:55.885129976 +0200
+++ ./nss/lib/freebl/blinit.c	2018-04-10 17:20:26.723480086 +0200
@@ -91,7 +91,7 @@
 }
 #endif /* NSS_X86_OR_X64 */
 
-#if (defined(__aarch64__) || defined(__arm__)) && !defined(__ANDROID__)
+#if (defined(__aarch64__) || defined(__arm__)) && defined(__linux__)
 #if defined(__GNUC__) && __GNUC__ >= 2 && defined(__ELF__)
 #include <sys/auxv.h>
 extern unsigned long getauxval(unsigned long type) __attribute__((weak));
@@ -100,9 +100,9 @@
 #define AT_HWCAP2
 #define AT_HWCAP
 #endif /* defined(__GNUC__) && __GNUC__ >= 2 && defined(__ELF__)*/
-#endif /* (defined(__aarch64__) || defined(__arm__)) && !defined(__ANDROID__) */
+#endif /* (defined(__aarch64__) || defined(__arm__)) && defined(__linux__) */
 
-#if defined(__aarch64__) && !defined(__ANDROID__)
+#if defined(__aarch64__) && defined(__linux__)
 // Defines from hwcap.h in Linux kernel - ARM64
 #define HWCAP_AES (1 << 3)
 #define HWCAP_PMULL (1 << 4)
@@ -124,9 +124,9 @@
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
@@ -155,7 +155,7 @@
         arm_neon_support_ = hwcaps & HWCAP_NEON && disable_arm_neon == NULL;
     }
 }
-#endif /* defined(__arm__) && !defined(__ANDROID__) */
+#endif /* defined(__arm__) && defined(__linux__) */
 
 // Enable when Firefox can use it.
 // #if defined(__ANDROID__) && (defined(__arm__) || defined(__aarch64__))
@@ -238,7 +238,7 @@
 {
 #ifdef NSS_X86_OR_X64
     CheckX86CPUSupport();
-#elif (defined(__aarch64__) || defined(__arm__)) && !defined(__ANDROID__)
+#elif (defined(__aarch64__) || defined(__arm__)) && defined(__linux__)
     CheckARMSupport();
 #endif
     return PR_SUCCESS;
