$NetBSD: patch-hotspot_src_share_vm_services_memTracker.hpp,v 1.1 2018/08/20 17:24:00 tnn Exp $

clang>6 fixes.
Ref: http://mail.openjdk.java.net/pipermail/bsd-port-dev/2018-May/003177.html

--- hotspot/src/share/vm/services/memTracker.hpp.orig	2018-05-26 23:58:31.000000000 +0000
+++ hotspot/src/share/vm/services/memTracker.hpp
@@ -31,8 +31,8 @@
 
 #if !INCLUDE_NMT
 
-#define CURRENT_PC   NativeCallStack::EMPTY_STACK
-#define CALLER_PC    NativeCallStack::EMPTY_STACK
+#define CURRENT_PC   NativeCallStack::EMPTY_STACK()
+#define CALLER_PC    NativeCallStack::EMPTY_STACK()
 
 class Tracker : public StackObj {
  public:
@@ -83,9 +83,9 @@ class MemTracker : AllStatic {
 extern volatile bool NMT_stack_walkable;
 
 #define CURRENT_PC ((MemTracker::tracking_level() == NMT_detail && NMT_stack_walkable) ? \
-                    NativeCallStack(0, true) : NativeCallStack::EMPTY_STACK)
+                    NativeCallStack(0, true) : NativeCallStack::EMPTY_STACK())
 #define CALLER_PC  ((MemTracker::tracking_level() == NMT_detail && NMT_stack_walkable) ?  \
-                    NativeCallStack(1, true) : NativeCallStack::EMPTY_STACK)
+                    NativeCallStack(1, true) : NativeCallStack::EMPTY_STACK())
 
 class MemBaseline;
 class Mutex;
