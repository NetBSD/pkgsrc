$NetBSD: patch-src_hotspot_cpu_aarch64_templateInterpreterGenerator__aarch64.cpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Backport a bugfix appeared in Java 22:
https://github.com/openjdk/jdk/commit/50f31240555888018f0f496ab29c8a5932dce459

--- src/hotspot/cpu/aarch64/templateInterpreterGenerator_aarch64.cpp.orig	2025-08-01 18:02:38.517120527 +0000
+++ src/hotspot/cpu/aarch64/templateInterpreterGenerator_aarch64.cpp
@@ -1365,6 +1365,9 @@ address TemplateInterpreterGenerator::ge
   __ get_method(rmethod);
   // result potentially in r0 or v0
 
+  // Restore cpu control state after JNI call
+  __ restore_cpu_control_state_after_jni(rscratch1, rscratch2);
+
   // make room for the pushes we're about to do
   __ sub(rscratch1, esp, 4 * wordSize);
   __ andr(sp, rscratch1, -16);
