$NetBSD: patch-hotspot_src_share_vm_runtime_arguments.cpp,v 1.1 2015/08/27 19:03:59 joerg Exp $

On 64bit systems, the JVM by default reserves 1GB VA to mangle class
pointers into a 32bit representation. When the available memory is less
than 16GB, e.g. due to process limits, scale this down. Even unused
pages waste system resources and the default limit can stop the JVM
from starting with ulimit -v 2G.

--- hotspot/src/share/vm/runtime/arguments.cpp.orig	2015-08-26 15:02:34.000000000 +0000
+++ hotspot/src/share/vm/runtime/arguments.cpp
@@ -1808,6 +1808,12 @@ void Arguments::set_heap_size() {
     FLAG_SET_ERGO(uintx, MaxHeapSize, (uintx)reasonable_max);
   }
 
+  if (FLAG_IS_DEFAULT(CompressedClassSpaceSize)) {
+    julong reasonable_max = phys_mem / 16;
+    reasonable_max = MIN2(reasonable_max, (julong)CompressedClassSpaceSize);
+    FLAG_SET_ERGO(uintx, CompressedClassSpaceSize, (uintx)reasonable_max);
+  }
+
   // If the minimum or initial heap_size have not been set or requested to be set
   // ergonomically, set them accordingly.
   if (InitialHeapSize == 0 || min_heap_size() == 0) {
