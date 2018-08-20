$NetBSD: patch-hotspot_src_share_vm_services_memTracker.cpp,v 1.1 2018/08/20 17:24:00 tnn Exp $

clang>6 fixes.
Ref: http://mail.openjdk.java.net/pipermail/bsd-port-dev/2018-May/003177.html

--- hotspot/src/share/vm/services/memTracker.cpp.orig	2018-05-26 23:58:31.000000000 +0000
+++ hotspot/src/share/vm/services/memTracker.cpp
@@ -67,10 +67,6 @@ NMT_TrackingLevel MemTracker::init_track
     os::unsetenv(buf);
   }
 
-  // Construct NativeCallStack::EMPTY_STACK. It may get constructed twice,
-  // but it is benign, the results are the same.
-  ::new ((void*)&NativeCallStack::EMPTY_STACK) NativeCallStack(0, false);
-
   if (!MallocTracker::initialize(level) ||
       !VirtualMemoryTracker::initialize(level)) {
     level = NMT_off;
