$NetBSD: patch-src_hotspot_share_runtime_thread.cpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/runtime/thread.cpp.orig	2025-08-01 08:15:36.406910243 +0000
+++ src/hotspot/share/runtime/thread.cpp
@@ -2547,7 +2547,7 @@ void JavaThread::check_safepoint_and_sus
 // thread state is _thread_in_native_trans.
 void JavaThread::check_special_condition_for_native_trans(JavaThread *thread) {
   // Enable WXWrite: called directly from interpreter native wrapper.
-  MACOS_AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
+  AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
 
   check_safepoint_and_suspend_for_native_trans(thread);
 
