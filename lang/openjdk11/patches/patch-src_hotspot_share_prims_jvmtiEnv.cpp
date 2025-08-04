$NetBSD: patch-src_hotspot_share_prims_jvmtiEnv.cpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/prims/jvmtiEnv.cpp.orig	2025-08-01 08:08:39.663737473 +0000
+++ src/hotspot/share/prims/jvmtiEnv.cpp
@@ -172,7 +172,7 @@ JvmtiEnv::GetThreadLocalStorage(jthread 
     // other than the current thread is required we need to transition
     // from native so as to resolve the jthread.
 
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, current_thread));
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, current_thread));
     ThreadInVMfromNative __tiv(current_thread);
     VM_ENTRY_BASE(jvmtiError, JvmtiEnv::GetThreadLocalStorage , current_thread)
     debug_only(VMNativeEntryWrapper __vew;)
@@ -3288,7 +3288,7 @@ JvmtiEnv::RawMonitorEnter(JvmtiRawMonito
     int r = 0;
     Thread* thread = Thread::current();
     // 8266889: raw_enter changes Java thread state, needs WXWrite
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));
 
     if (thread->is_Java_thread()) {
       JavaThread* current_thread = (JavaThread*)thread;
@@ -3387,7 +3387,7 @@ JvmtiEnv::RawMonitorWait(JvmtiRawMonitor
   int r = 0;
   Thread* thread = Thread::current();
   // 8266889: raw_wait changes Java thread state, needs WXWrite
-  MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));
+  AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));
 
   if (thread->is_Java_thread()) {
     JavaThread* current_thread = (JavaThread*)thread;
