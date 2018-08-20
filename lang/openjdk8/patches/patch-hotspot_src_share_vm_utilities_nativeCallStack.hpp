$NetBSD: patch-hotspot_src_share_vm_utilities_nativeCallStack.hpp,v 1.1 2018/08/20 17:24:00 tnn Exp $

clang>6 fixes.
Ref: http://mail.openjdk.java.net/pipermail/bsd-port-dev/2018-May/003177.html

--- hotspot/src/share/vm/utilities/nativeCallStack.hpp.orig	2018-05-26 23:58:31.000000000 +0000
+++ hotspot/src/share/vm/utilities/nativeCallStack.hpp
@@ -53,7 +53,7 @@
  */
 class NativeCallStack : public StackObj {
  public:
-  static const NativeCallStack EMPTY_STACK;
+  static const NativeCallStack& EMPTY_STACK();
 
  private:
   address   _stack[NMT_TrackingStackDepth];
