$NetBSD: patch-js_src_asmjs_AsmJSSignalHandlers.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

Increase portability for non-x86 Darwin by not hardwiring
x86_THREAD_STATE.

--- js/src/asmjs/AsmJSSignalHandlers.cpp.orig	2015-05-04 00:43:23.000000000 +0000
+++ js/src/asmjs/AsmJSSignalHandlers.cpp
@@ -637,10 +637,11 @@ HandleMachException(JSRuntime* rt, const
     mach_port_t rtThread = request.body.thread.name;
 
     // Read out the JSRuntime thread's register state.
-    x86_thread_state_t state;
-    unsigned int count = x86_THREAD_STATE_COUNT;
+    moz_platform_thread_state_t state;
+    thread_state_flavor_t flavor = MOZ_PLATFORM_THREAD_STATE_FLAVOR;
+    mach_msg_type_number_t count = MOZ_PLATFORM_THREAD_STATE_COUNT;
     kern_return_t kret;
-    kret = thread_get_state(rtThread, x86_THREAD_STATE, (thread_state_t)&state, &count);
+    kret = thread_get_state(rtThread, flavor, (thread_state_t)&state, &count);
     if (kret != KERN_SUCCESS)
         return false;
 
