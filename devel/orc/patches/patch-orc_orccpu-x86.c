$NetBSD: patch-orc_orccpu-x86.c,v 1.1 2024/08/03 10:41:21 nia Exp $

From e184d18fd6e4fa18178b30871903cdaa839093fe Mon Sep 17 00:00:00 2001
From: "L. E. Segovia" <amy@centricular.com>
Date: Fri, 19 Jul 2024 11:40:28 -0300
Subject: [PATCH] x86: work around old GCC versions (pre 9.0) having broken
 xgetbv implementations

See https://gcc.gnu.org/bugzilla/show_bug.cgi?id=71659

Part-of: <https://gitlab.freedesktop.org/gstreamer/orc/-/merge_requests/194>

--- orc/orccpu-x86.c.orig	2024-07-19 11:02:41.000000000 +0000
+++ orc/orccpu-x86.c
@@ -34,6 +34,19 @@
 
 #ifdef _MSC_VER
 #  include <intrin.h>
+#elif defined(__GNUC__)
+#if __GNUC__ >= 8 && __GNUC__ < 9
+// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=71659
+#  include <xsaveintrin.h>
+#elif __GNUC__ < 8
+#  define ORC_NEEDS_ASM_XSAVE 1
+#endif
+#endif
+
+#if !defined(_MSC_VER) || defined(__clang__)
+#define ORC_TARGET_XSAVE __attribute__((target("xsave")))
+#else
+#define ORC_TARGET_XSAVE
 #endif
 
 #include <orc/orcdebug.h>
@@ -304,15 +317,19 @@ orc_x86_cpuid_get_branding_string (void)
 // Checks if XMM and YMM state are enabled in XCR0.
 // See 14.3 DETECTION OF INTEL® AVX INSTRUCTIONS on the
 // Intel® 64 and IA-32 Architectures Software Developer’s Manual
-#if !defined(_MSC_VER) || defined(__clang__)
-#define ORC_TARGET_XSAVE __attribute__((target("xsave")))
+#ifdef ORC_NEEDS_ASM_XSAVE
+static orc_bool check_xcr0_ymm()
+{
+  uint32_t xcr0;
+  __asm__ ("xgetbv" : "=a" (xcr0) : "c" (0) : "%edx" );
+  return ((xcr0 & 6U) == 6U);
+}
 #else
-#define ORC_TARGET_XSAVE
-#endif
 static orc_bool ORC_TARGET_XSAVE check_xcr0_ymm()
 {
   return (_xgetbv(0) & 6U) != 0U;
 }
+#endif
 
 static void
 orc_x86_cpuid_handle_standard_flags (void)
