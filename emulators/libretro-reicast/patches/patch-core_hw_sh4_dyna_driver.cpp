$NetBSD: patch-core_hw_sh4_dyna_driver.cpp,v 1.1 2018/10/13 17:02:17 nia Exp $

Add support for NetBSD.

--- core/hw/sh4/dyna/driver.cpp.orig	2018-10-12 17:39:34.000000000 +0000
+++ core/hw/sh4/dyna/driver.cpp
@@ -34,7 +34,8 @@ u8 SH4_TCB[CODE_SIZE+4096]
 #if defined(_WIN32) || FEAT_SHREC != DYNAREC_JIT
 	;
 #elif defined(__linux__) || defined(__HAIKU__) || \
-      defined(__FreeBSD__) || defined(__DragonFly__)
+      defined(__FreeBSD__) || defined(__DragonFly__) || \
+      defined(__NetBSD__)
 	__attribute__((section(".text")));
 #elif defined(__MACH__)
 	__attribute__((section("__TEXT,.text")));
