$NetBSD: patch-hotspot_src_share_vm_services_mallocSiteTable.hpp,v 1.1 2018/08/20 17:24:00 tnn Exp $

clang>6 fixes.
Ref: http://mail.openjdk.java.net/pipermail/bsd-port-dev/2018-May/003177.html

--- hotspot/src/share/vm/services/mallocSiteTable.hpp.orig	2018-05-26 23:58:31.000000000 +0000
+++ hotspot/src/share/vm/services/mallocSiteTable.hpp
@@ -42,7 +42,7 @@ class MallocSite : public AllocationSite
 
  public:
   MallocSite() :
-    AllocationSite<MemoryCounter>(NativeCallStack::EMPTY_STACK), _flags(mtNone) {}
+    AllocationSite<MemoryCounter>(NativeCallStack::EMPTY_STACK()), _flags(mtNone) {}
 
   MallocSite(const NativeCallStack& stack, MEMFLAGS flags) :
     AllocationSite<MemoryCounter>(stack), _flags(flags) {}
