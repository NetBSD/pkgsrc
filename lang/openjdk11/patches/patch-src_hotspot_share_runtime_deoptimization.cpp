$NetBSD: patch-src_hotspot_share_runtime_deoptimization.cpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/runtime/deoptimization.cpp.orig	2025-08-01 08:12:23.402260027 +0000
+++ src/hotspot/share/runtime/deoptimization.cpp
@@ -2096,7 +2096,7 @@ Deoptimization::update_method_data_from_
 
 Deoptimization::UnrollBlock* Deoptimization::uncommon_trap(JavaThread* thread, jint trap_request, jint exec_mode) {
   // Enable WXWrite: current function is called from methods compiled by C2 directly
-  MACOS_AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
+  AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
 
   if (TraceDeoptimization) {
     tty->print("Uncommon trap ");
