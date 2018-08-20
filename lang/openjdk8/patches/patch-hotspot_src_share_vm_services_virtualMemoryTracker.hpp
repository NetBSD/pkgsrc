$NetBSD: patch-hotspot_src_share_vm_services_virtualMemoryTracker.hpp,v 1.1 2018/08/20 17:24:00 tnn Exp $

clang>6 fixes.
Ref: http://mail.openjdk.java.net/pipermail/bsd-port-dev/2018-May/003177.html

--- hotspot/src/share/vm/services/virtualMemoryTracker.hpp.orig	2018-05-26 23:58:31.000000000 +0000
+++ hotspot/src/share/vm/services/virtualMemoryTracker.hpp
@@ -305,7 +305,7 @@ class ReservedMemoryRegion : public Virt
 
 
   ReservedMemoryRegion(address base, size_t size) :
-    VirtualMemoryRegion(base, size), _stack(NativeCallStack::EMPTY_STACK), _flag(mtNone),
+    VirtualMemoryRegion(base, size), _stack(NativeCallStack::EMPTY_STACK()), _flag(mtNone),
     _all_committed(false) { }
 
   // Copy constructor
