$NetBSD: patch-src_lib_util_kmemoryinfo.cpp,v 1.2 2026/09/06 10:05:12 markd Exp $

Add NetBSD Memory info

--- src/lib/util/kmemoryinfo.cpp.orig	2026-08-07 20:39:44.000000000 +0000
+++ src/lib/util/kmemoryinfo.cpp
@@ -39,6 +39,9 @@ Q_LOGGING_CATEGORY(LOG_KMEMORYINFO, "kf.
      #include <stdlib.h>
      #include <strings.h>
      #include <unistd.h>
+#elif defined(Q_OS_NETBSD)
+     #include <sys/sysctl.h>
+     #include <uvm/uvm_extern.h>
 #elif defined(Q_OS_HURD)
      extern "C" {
           #include <mach/mach.h>
@@ -548,6 +551,29 @@ bool KMemoryInfo::update()
 
     return true;
 }
+#elif defined(Q_OS_NETBSD)
+/*****************************************************************************
+ * NetBSD
+ ****************************************************************************/
+
+bool KMemoryInfo::update()
+{
+    int uvmexp_mib[] = {CTL_VM, VM_UVMEXP2};
+    struct uvmexp_sysctl uvmexp;
+    size_t size = sizeof(struct uvmexp_sysctl);
+    if (sysctl(uvmexp_mib, 2, &uvmexp, &size, NULL, 0) == -1) {
+        bzero(&uvmexp, sizeof(struct uvmexp_sysctl));
+        return false;
+    }
+    d->m_totalPhysical = uvmexp.npages * uvmexp.pagesize / 1024;
+    d->m_availablePhysical = (uvmexp.npages - uvmexp.wired) * uvmexp.pagesize / 1024;
+    d->m_freePhysical = uvmexp.free * uvmexp.pagesize / 1024;
+    d->m_totalSwapFile = uvmexp.swpages * uvmexp.pagesize / 1024;
+    d->m_freeSwapFile = (uvmexp.swpages - uvmexp.swpginuse) * uvmexp.pagesize / 1024;
+    d->m_cached = (uvmexp.anonpages + uvmexp.filepages + uvmexp.execpages) * uvmexp.pagesize / 1024;
+
+    return true;
+}
 #else
 /*****************************************************************************
  * Unsupported platform
