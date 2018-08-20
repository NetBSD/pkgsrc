$NetBSD: patch-hotspot_src_share_vm_services_virtualMemoryTracker.cpp,v 1.1 2018/08/20 17:24:00 tnn Exp $

clang>6 fixes.
Ref: http://mail.openjdk.java.net/pipermail/bsd-port-dev/2018-May/003177.html

--- hotspot/src/share/vm/services/virtualMemoryTracker.cpp.orig	2018-05-26 23:58:31.000000000 +0000
+++ hotspot/src/share/vm/services/virtualMemoryTracker.cpp
@@ -167,7 +167,7 @@ bool ReservedMemoryRegion::remove_uncomm
           // higher part
           address high_base = addr + sz;
           size_t  high_size = top - high_base;
-          CommittedMemoryRegion high_rgn(high_base, high_size, NativeCallStack::EMPTY_STACK);
+          CommittedMemoryRegion high_rgn(high_base, high_size, NativeCallStack::EMPTY_STACK());
           return add_committed_region(high_rgn);
         } else {
           return false;
