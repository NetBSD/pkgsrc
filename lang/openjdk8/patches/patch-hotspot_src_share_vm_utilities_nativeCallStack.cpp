$NetBSD: patch-hotspot_src_share_vm_utilities_nativeCallStack.cpp,v 1.1 2018/08/20 17:24:00 tnn Exp $

clang>6 fixes.
Ref: http://mail.openjdk.java.net/pipermail/bsd-port-dev/2018-May/003177.html

--- hotspot/src/share/vm/utilities/nativeCallStack.cpp.orig	2018-05-26 23:58:31.000000000 +0000
+++ hotspot/src/share/vm/utilities/nativeCallStack.cpp
@@ -27,7 +27,10 @@
 #include "utilities/globalDefinitions.hpp"
 #include "utilities/nativeCallStack.hpp"
 
-const NativeCallStack NativeCallStack::EMPTY_STACK(0, false);
+const NativeCallStack& NativeCallStack::EMPTY_STACK() {
+  static const NativeCallStack empty(0, false);
+  return empty;
+}
 
 NativeCallStack::NativeCallStack(int toSkip, bool fillStack) :
   _hash_value(0) {
