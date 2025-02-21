$NetBSD: patch-libs_pdcore_pc_config.h,v 1.1 2025/02/21 17:08:52 chuck Exp $

Add support for MACOSX on aarch64 platform

--- libs/pdcore/pc_config.h.orig	2010-04-29 13:50:04.000000000 +0000
+++ libs/pdcore/pc_config.h
@@ -143,7 +143,8 @@
 /* try to identify the Mac OS X command line compiler */
 
 #if defined(__APPLE__) && (defined(__ppc__) || \
-    defined(__i386__) || defined(__ppc64__) || defined(__x86_64__))
+    defined(__i386__) || defined(__ppc64__) || defined(__x86_64__) || \
+    defined(__aarch64__))
 
 #define MACOSX
 
@@ -164,6 +165,10 @@
 #define PDF_PLATFORM    PDF_MAC_PLATFORM" 64"
 #endif /* __x86_64__ */
 
+#if defined(__aarch64__)
+#define PDF_PLATFORM    PDF_MAC_PLATFORM" aarch64"
+#endif /* __aarch64__ */
+
 #if !defined(PDF_PLATFORM)
 #define PDF_PLATFORM    PDF_MAC_PLATFORM
 #endif
