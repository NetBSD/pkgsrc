$NetBSD: patch-src_hotspot_os__cpu_bsd__aarch64_os__bsd__aarch64.cpp,v 1.3 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp.orig	2025-08-01 08:01:30.302760008 +0000
+++ src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp
@@ -1053,6 +1053,7 @@ JVM_handle_bsd_signal(int sig,
 
       // check if fault address is within thread stack
       if (thread->on_local_stack(addr)) {
+        AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
         // stack overflow
         if (thread->in_stack_yellow_reserved_zone(addr)) {
           if (thread->thread_state() == _thread_in_Java) {
@@ -1100,6 +1101,7 @@ JVM_handle_bsd_signal(int sig,
     if (thread->thread_state() == _thread_in_Java) {
       // Java thread running in Java code => find exception handler if any
       // a fault inside compiled code, the interpreter, or a stub
+      AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
 
       // Handle signal from NativeJump::patch_verified_entry().
       if ((sig == SIGILL || sig == SIGTRAP)
