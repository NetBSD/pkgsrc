$NetBSD: patch-core_hw_aica_dsp__x64.cpp,v 1.1 2020/05/31 15:20:22 nia Exp $

Add support for more operating systems.

--- core/hw/aica/dsp_x64.cpp.orig	2020-05-29 12:45:55.000000000 +0000
+++ core/hw/aica/dsp_x64.cpp
@@ -33,7 +33,10 @@
 DECL_ALIGN(4096) static u8 CodeBuffer[32 * 1024]
 #if defined(_WIN32) || defined(__HAIKU__)
 	;
-#elif defined(__linux__)
+#elif defined(__linux__) || \
+	defined(__FreeBSD__) || \
+	defined(__DragonFly__) || \
+	defined(__NetBSD__)
 	__attribute__((section(".text")));
 #elif defined(__MACH__)
 	__attribute__((section("__TEXT,.text")));
