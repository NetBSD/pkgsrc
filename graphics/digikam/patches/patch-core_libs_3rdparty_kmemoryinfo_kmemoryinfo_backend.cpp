$NetBSD: patch-core_libs_3rdparty_kmemoryinfo_kmemoryinfo_backend.cpp,v 1.1 2012/03/21 21:14:47 markd Exp $

Make memory info backend compile on NetBSD.  Need to check
it actually returns the correct results.

--- core/libs/3rdparty/kmemoryinfo/kmemoryinfo_backend.cpp.orig	2012-01-03 00:32:23.000000000 +0000
+++ core/libs/3rdparty/kmemoryinfo/kmemoryinfo_backend.cpp
@@ -57,7 +57,8 @@ static bool fillMemoryInfo(Digikam::KMem
 #if defined(Q_OS_NETBSD)
 #include <sys/param.h>
 #include <sys/time.h>
-#include <uvm/uvm.h>
+#include <sys/sysctl.h>
+#include <uvm/uvm_extern.h>
 #endif
 #if defined(Q_OS_OPENBSD)
 #include <sys/param.h>
@@ -128,7 +129,7 @@ struct uvmexp *sg_get_uvmexp() {
     int mib[2];
     size_t size = sizeof(struct uvmexp);
     static struct uvmexp uvm;
-    struct uvmexp *new;
+    /* struct uvmexp *new; */
 
     mib[0] = CTL_VM;
     mib[1] = VM_UVMEXP;
@@ -332,7 +333,7 @@ bool get_mem_stats(Digikam::KMemoryInfo:
 
     data->totalRam = uvm->pagesize * uvm->npages;
     data->cacheRam = uvm->pagesize * (uvm->filepages + uvm->execpages);
-    data->freeRam  = uvm->pagesize * (uvm->free + uvm->inactive);
+    data->freeRam  = uvm->pagesize * (uvm->free + uvm->paging);
     data->usedRam  = data->totalRam - data->freeRam;
 #endif
 
