$NetBSD: patch-src_hotspot_cpu_aarch64_sharedRuntime__aarch64.cpp,v 1.1 2025/08/06 08:47:16 pho Exp $

Backport a bugfix appeared in Java 22:
https://github.com/openjdk/jdk/commit/50f31240555888018f0f496ab29c8a5932dce459

--- src/hotspot/cpu/aarch64/sharedRuntime_aarch64.cpp.orig	2025-08-01 17:56:57.114189168 +0000
+++ src/hotspot/cpu/aarch64/sharedRuntime_aarch64.cpp
@@ -1806,6 +1806,9 @@ nmethod* SharedRuntime::generate_native_
   intptr_t return_pc = (intptr_t) __ pc();
   oop_maps->add_gc_map(return_pc - start, map);
 
+  // Restore cpu control state after JNI call
+  __ restore_cpu_control_state_after_jni(rscratch1, rscratch2);
+
   // Unpack native results.
   switch (ret_type) {
   case T_BOOLEAN: __ c2bool(r0);                     break;
