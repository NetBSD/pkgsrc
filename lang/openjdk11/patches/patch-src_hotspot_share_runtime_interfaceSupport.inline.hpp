$NetBSD: patch-src_hotspot_share_runtime_interfaceSupport.inline.hpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/runtime/interfaceSupport.inline.hpp.orig	2025-04-19 23:57:10.000000000 +0000
+++ src/hotspot/share/runtime/interfaceSupport.inline.hpp
@@ -405,7 +405,7 @@ class RuntimeHistogramElement : public H
 #define VM_LEAF_BASE(result_type, header)                            \
   TRACE_CALL(result_type, header)                                    \
   debug_only(NoHandleMark __hm;)                                     \
-  MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite,                    \
+  AARCH64_ONLY(ThreadWXEnable __wx(WXWrite,                          \
                                          Thread::current()));        \
   os::verify_stack_alignment();                                      \
   /* begin of body */
@@ -444,7 +444,7 @@ class RuntimeHistogramElement : public H
 
 #define IRT_ENTRY(result_type, header)                               \
   result_type header {                                               \
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));        \
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));              \
     ThreadInVMfromJava __tiv(thread);                                \
     VM_ENTRY_BASE(result_type, header, thread)                       \
     debug_only(VMEntryWrapper __vew;)
@@ -458,7 +458,7 @@ class RuntimeHistogramElement : public H
 
 #define IRT_ENTRY_NO_ASYNC(result_type, header)                      \
   result_type header {                                               \
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));        \
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));              \
     ThreadInVMfromJavaNoAsyncException __tiv(thread);                \
     VM_ENTRY_BASE(result_type, header, thread)                       \
     debug_only(VMEntryWrapper __vew;)
@@ -467,7 +467,7 @@ class RuntimeHistogramElement : public H
 
 #define JRT_ENTRY(result_type, header)                               \
   result_type header {                                               \
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));        \
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));              \
     ThreadInVMfromJava __tiv(thread);                                \
     VM_ENTRY_BASE(result_type, header, thread)                       \
     debug_only(VMEntryWrapper __vew;)
@@ -481,7 +481,7 @@ class RuntimeHistogramElement : public H
 
 #define JRT_ENTRY_NO_ASYNC(result_type, header)                      \
   result_type header {                                               \
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));        \
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));              \
     ThreadInVMfromJavaNoAsyncException __tiv(thread);                \
     VM_ENTRY_BASE(result_type, header, thread)                       \
     debug_only(VMEntryWrapper __vew;)
@@ -490,7 +490,7 @@ class RuntimeHistogramElement : public H
 // to get back into Java from the VM
 #define JRT_BLOCK_ENTRY(result_type, header)                         \
   result_type header {                                               \
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));        \
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));              \
     TRACE_CALL(result_type, header)                                  \
     HandleMarkCleaner __hm(thread);
 
@@ -521,7 +521,7 @@ extern "C" {                            
   result_type JNICALL header {                                       \
     JavaThread* thread=JavaThread::thread_from_jni_environment(env); \
     assert( !VerifyJNIEnvThread || (thread == Thread::current()), "JNIEnv is only valid in same thread"); \
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));        \
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));              \
     ThreadInVMfromNative __tiv(thread);                              \
     debug_only(VMNativeEntryWrapper __vew;)                          \
     VM_ENTRY_BASE(result_type, header, thread)
@@ -534,7 +534,7 @@ extern "C" {                            
   result_type JNICALL header {                                       \
     JavaThread* thread=JavaThread::thread_from_jni_environment(env); \
     assert( !VerifyJNIEnvThread || (thread == Thread::current()), "JNIEnv is only valid in same thread"); \
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));        \
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));              \
     ThreadInVMfromNative __tiv(thread);                              \
     debug_only(VMNativeEntryWrapper __vew;)                          \
     VM_QUICK_ENTRY_BASE(result_type, header, thread)
@@ -559,7 +559,7 @@ extern "C" {                            
 extern "C" {                                                         \
   result_type JNICALL header {                                       \
     JavaThread* thread=JavaThread::thread_from_jni_environment(env); \
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));        \
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));              \
     ThreadInVMfromNative __tiv(thread);                              \
     debug_only(VMNativeEntryWrapper __vew;)                          \
     VM_ENTRY_BASE(result_type, header, thread)
@@ -569,7 +569,7 @@ extern "C" {                            
 extern "C" {                                                         \
   result_type JNICALL header {                                       \
     JavaThread* thread = JavaThread::current();                      \
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));        \
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));              \
     ThreadInVMfromNative __tiv(thread);                              \
     debug_only(VMNativeEntryWrapper __vew;)                          \
     VM_ENTRY_BASE(result_type, header, thread)
@@ -579,7 +579,7 @@ extern "C" {                            
 extern "C" {                                                         \
   result_type JNICALL header {                                       \
     JavaThread* thread=JavaThread::thread_from_jni_environment(env); \
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));        \
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thread));              \
     ThreadInVMfromNative __tiv(thread);                              \
     debug_only(VMNativeEntryWrapper __vew;)                          \
     VM_QUICK_ENTRY_BASE(result_type, header, thread)
