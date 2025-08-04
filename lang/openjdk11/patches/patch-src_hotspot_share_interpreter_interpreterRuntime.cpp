$NetBSD: patch-src_hotspot_share_interpreter_interpreterRuntime.cpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/interpreter/interpreterRuntime.cpp.orig	2025-08-01 08:05:13.541716842 +0000
+++ src/hotspot/share/interpreter/interpreterRuntime.cpp
@@ -1007,7 +1007,7 @@ IRT_END
 
 nmethod* InterpreterRuntime::frequency_counter_overflow(JavaThread* thread, address branch_bcp) {
   // Enable WXWrite: the function is called directly by interpreter.
-  MACOS_AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
+  AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
 
   nmethod* nm = frequency_counter_overflow_inner(thread, branch_bcp);
   assert(branch_bcp != NULL || nm == NULL, "always returns null for non OSR requests");
