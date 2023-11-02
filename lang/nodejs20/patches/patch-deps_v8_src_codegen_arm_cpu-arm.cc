$NetBSD: patch-deps_v8_src_codegen_arm_cpu-arm.cc,v 1.1 2023/11/02 13:16:54 adam Exp $

port to NetBSD/arm.

--- deps/v8/src/codegen/arm/cpu-arm.cc.orig	2020-10-07 10:47:41.000000000 -0700
+++ deps/v8/src/codegen/arm/cpu-arm.cc	2020-10-17 00:16:51.732785305 -0700
@@ -19,6 +19,10 @@
 
 #include "src/codegen/cpu-features.h"
 
+#if V8_OS_NETBSD
+#include <machine/sysarch.h>
+#endif
+
 namespace v8 {
 namespace internal {
 
@@ -32,6 +36,8 @@
   struct arm_sync_icache_args args = {
       .addr = reinterpret_cast<uintptr_t>(start), .len = size};
   sysarch(ARM_SYNC_ICACHE, reinterpret_cast<void*>(&args));
+#elif V8_OS_NETBSD
+  arm_sync_icache(reinterpret_cast<uintptr_t>(start), size);
 #else
   register uint32_t beg asm("r0") = reinterpret_cast<uint32_t>(start);
   register uint32_t end asm("r1") = beg + size;
