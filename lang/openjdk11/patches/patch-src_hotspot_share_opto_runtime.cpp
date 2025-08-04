$NetBSD: patch-src_hotspot_share_opto_runtime.cpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/opto/runtime.cpp.orig	2025-08-01 08:07:00.594301599 +0000
+++ src/hotspot/share/opto/runtime.cpp
@@ -1447,7 +1447,7 @@ address OptoRuntime::handle_exception_C(
 address OptoRuntime::rethrow_C(oopDesc* exception, JavaThread* thread, address ret_pc) {
 
   // Enable WXWrite: the function called directly by compiled code.
-  MACOS_AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
+  AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
 
 #ifndef PRODUCT
   SharedRuntime::_rethrow_ctr++;               // count rethrows
