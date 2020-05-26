$NetBSD: patch-core_libs_kmemoryinfo_libstatgrab_kmemoryinfo_backend.cpp,v 1.2 2020/05/26 11:27:21 joerg Exp $

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
@@ -151,7 +152,28 @@ kvm_t* sg_get_kvm2()
 }
 #endif // (defined(Q_OS_FREEBSD) && !defined(FREEBSD5)) || defined(DFBSD)
 
-#if defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
+#if defined(Q_OS_NETBSD)
+struct uvmexp_sysctl* sg_get_uvmexp()
+{
+    int                  mib[2];
+    static struct uvmexp_sysctl uvm;
+    size_t               size = sizeof(uvm);
+//    struct uvmexp*       new;
+
+    mib[0] = CTL_VM;
+    mib[1] = VM_UVMEXP2;
+
+    if (sysctl(mib, 2, &uvm, &size, NULL, 0) < 0)
+    {
+        //sg_set_error_with_errno(SG_ERROR_SYSCTL, "CTL_VM.VM_UVMEXP");
+        return NULL;
+    }
+
+    return &uvm;
+}
+#endif // defined(Q_OS_NETBSD)
+
+#if defined(Q_OS_OPENBSD)
 struct uvmexp* sg_get_uvmexp()
 {
     int                  mib[2];
@@ -170,7 +192,7 @@ struct uvmexp* sg_get_uvmexp()
 
     return &uvm;
 }
-#endif // defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
+#endif // defined(Q_OS_OPENBSD)
 
 #ifdef Q_OS_HPUX
 struct pst_KMemoryInfo::static* sg_get_pstat_static()
@@ -229,7 +251,7 @@ int get_mem_stats(Digikam::KMemoryInfo::
 #endif // defined(Q_OS_FREEBSD) || defined(Q_OS_DFBSD)
 
 #if defined(Q_OS_NETBSD)
-    struct uvmexp* uvm = 0;
+    struct uvmexp_sysctl* uvm = 0;
 #endif // defined(Q_OS_NETBSD)
 
 #if defined(Q_OS_OPENBSD)
@@ -430,7 +452,7 @@ int get_mem_stats(Digikam::KMemoryInfo::
 
     data->totalRam = uvm->pagesize * uvm->npages;
     data->cacheRam = uvm->pagesize * (uvm->filepages + uvm->execpages);
-    data->freeRam  = uvm->pagesize * (uvm->free + uvm->inactive);
+    data->freeRam  = uvm->pagesize * (uvm->free + uvm->paging);
     data->usedRam  = data->totalRam - data->freeRam;
 
     return 1;
@@ -540,7 +562,12 @@ int get_mem_stats(Digikam::KMemoryInfo::
 #endif
 #include <unistd.h>
 #endif
-#if defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
+#if defined(Q_OS_NETBSD)
+#include <sys/param.h>
+#include <sys/time.h>
+#include <uvm/uvm_extern.h>
+#include <unistd.h>
+#elif defined(Q_OS_OPENBSD)
 #include <sys/param.h>
 #include <sys/time.h>
 #include <uvm/uvm.h>
@@ -593,9 +620,12 @@ int get_swap_stats(Digikam::KMemoryInfo:
 
 #endif // defined(Q_OS_FREEBSD)
 
-#if defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
+#if defined(Q_OS_OPENBSD)
     struct uvmexp* uvm = 0;
-#endif // defined(Q_OS_NETBSD) || defined(Q_OS_OPENBSD)
+#endif // defined(Q_OS_OPENBSD)
+#if defined(Q_OS_NETBSD)
+    struct uvmexp_sysctl* uvm = 0;
+#endif // defined(Q_OS_NETBSD)
 
 #ifdef Q_OS_WIN
     MEMORYSTATUSEX memstats;
