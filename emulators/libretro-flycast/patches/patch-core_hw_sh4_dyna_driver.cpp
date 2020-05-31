$NetBSD: patch-core_hw_sh4_dyna_driver.cpp,v 1.1 2020/05/31 15:20:22 nia Exp $

Add support for NetBSD.

--- core/hw/sh4/dyna/driver.cpp.orig	2020-05-29 12:45:55.000000000 +0000
+++ core/hw/sh4/dyna/driver.cpp
@@ -28,7 +28,7 @@ u8 SH4_TCB[CODE_SIZE + TEMP_CODE_SIZE + 
 #if defined(_WIN32) || FEAT_SHREC != DYNAREC_JIT
 	;
 #elif defined(__linux__) || defined(__HAIKU__) || \
-      defined(__FreeBSD__) || defined(__DragonFly__) || \
+      defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || \
 	  defined(HAVE_LIBNX)
 	__attribute__((section(".text")));
 #elif defined(__MACH__)
