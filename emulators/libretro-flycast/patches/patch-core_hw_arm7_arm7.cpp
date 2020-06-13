$NetBSD: patch-core_hw_arm7_arm7.cpp,v 1.1 2020/06/13 13:02:09 nia Exp $

Support non-Linux unixes with ELF.

--- core/hw/arm7/arm7.cpp.orig	2020-05-29 12:45:55.000000000 +0000
+++ core/hw/arm7/arm7.cpp
@@ -594,14 +594,10 @@ u8* ICache;
 extern const u32 ICacheSize=1024*1024;
 #ifdef _WIN32
 u8 ARM7_TCB[ICacheSize+4096];
-#elif defined(__linux__) || defined(HAVE_LIBNX)
-
-u8 ARM7_TCB[ICacheSize+4096] __attribute__((section(".text")));
-
 #elif defined(__MACH__)
 u8 ARM7_TCB[ICacheSize+4096] __attribute__((section("__TEXT, .text")));
 #else
-#error ARM7_TCB ALLOC
+u8 ARM7_TCB[ICacheSize+4096] __attribute__((section(".text")));
 #endif
 
 #include "rec-ARM/arm_emitter.h"
