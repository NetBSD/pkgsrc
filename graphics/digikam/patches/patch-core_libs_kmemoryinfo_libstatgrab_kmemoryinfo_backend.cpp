$NetBSD: patch-core_libs_kmemoryinfo_libstatgrab_kmemoryinfo_backend.cpp,v 1.1 2019/11/17 09:11:21 markd Exp $

Make memory info backend compile on NetBSD.  Need to check
it actually returns the correct results.

--- core/libs/kmemoryinfo/libstatgrab/kmemoryinfo_backend.cpp.orig	2019-11-03 09:04:00.000000000 +0000
+++ core/libs/kmemoryinfo/libstatgrab/kmemoryinfo_backend.cpp
@@ -73,7 +73,8 @@ static int fillMemoryInfo(Digikam::KMemo
 #if defined(Q_OS_NETBSD)
 #include <sys/param.h>
 #include <sys/time.h>
-#include <uvm/uvm.h>
+#include <sys/sysctl.h>
+#include <uvm/uvm_extern.h>
 #endif
 #if defined(Q_OS_OPENBSD)
 #include <sys/param.h>
@@ -430,7 +431,7 @@ int get_mem_stats(Digikam::KMemoryInfo::
 
     data->totalRam = uvm->pagesize * uvm->npages;
     data->cacheRam = uvm->pagesize * (uvm->filepages + uvm->execpages);
-    data->freeRam  = uvm->pagesize * (uvm->free + uvm->inactive);
+    data->freeRam  = uvm->pagesize * (uvm->free + uvm->paging);
     data->usedRam  = data->totalRam - data->freeRam;
 
     return 1;
