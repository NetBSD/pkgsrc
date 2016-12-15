$NetBSD: patch-hotspot_src_share_vm_gc__implementation_g1_heapRegionSet.hpp,v 1.1 2016/12/15 23:56:53 joerg Exp $

defined() is not evaluated inside macros when used later.

--- hotspot/src/share/vm/gc_implementation/g1/heapRegionSet.hpp.orig	2016-12-10 15:50:21.837559173 +0000
+++ hotspot/src/share/vm/gc_implementation/g1/heapRegionSet.hpp
@@ -35,7 +35,11 @@ typedef FormatBuffer<HRS_ERR_MSG_BUFSZ> 
 // HEAP_REGION_SET_FORCE_VERIFY to be 1, or in builds in which
 // asserts are compiled in.
 #ifndef HEAP_REGION_SET_FORCE_VERIFY
-#define HEAP_REGION_SET_FORCE_VERIFY defined(ASSERT)
+#  if defined(ASSERT)
+#  define HEAP_REGION_SET_FORCE_VERIFY 1
+#  else
+#  define HEAP_REGION_SET_FORCE_VERIFY 0
+#  endif
 #endif // HEAP_REGION_SET_FORCE_VERIFY
 
 class hrs_ext_msg;
