$NetBSD: patch-psutil_arch_netbsd_mem.c,v 1.1 2026/04/06 16:53:12 fox Exp $

Remove dependency on procfs, compute values correctly.

Upstream: https://github.com/giampaolo/psutil/pull/2805

--- psutil/arch/netbsd/mem.c.orig	2025-11-02 21:47:52.000000000 +0000
+++ psutil/arch/netbsd/mem.c
@@ -21,36 +21,70 @@ original(ish) implementations:
 
 #include "../../arch/all/init.h"
 
-
-// Virtual memory stats, taken from:
-// https://github.com/satterly/zabbix-stats/blob/master/src/libs/zbxsysinfo/
-//     netbsd/memory.c
+/*
+ * Virtual memory stats for NetBSD using VM_UVMEXP2 and VM_METER.
+ *
+ * Sources:
+ *   cached  = (filepages + execpages + anonpages) << pageshift  [btop]
+ *   buffers = filepages << pageshift                             [file cache excl. exec]
+ *   shared  = (t_vmshr + t_rmshr) * pagesize                    [vmtotal]
+ *   used    = (active + wired) << pageshift                      [htop/btop]
+ *   avail   = total - used                                       [htop/btop]
+ */
 PyObject *
 psutil_virtual_mem(PyObject *self, PyObject *args) {
-    size_t size;
     struct uvmexp_sysctl uv;
-    int mib[] = {CTL_VM, VM_UVMEXP2};
-    long long cached;
+    struct vmtotal vmdata;
+    int uvmexp_mib[] = {CTL_VM, VM_UVMEXP2};
+    int vmmeter_mib[] = {CTL_VM, VM_METER};
 
-    if (psutil_sysctl(mib, 2, &uv, sizeof(uv)) != 0)
+    if (psutil_sysctl(uvmexp_mib, 2, &uv, sizeof(uv)) != 0)
         return NULL;
+    if (psutil_sysctl(vmmeter_mib, 2, &vmdata, sizeof(vmdata)) != 0)
+        return NULL;
+
+    long long total    = (long long)uv.npages   << uv.pageshift;
+    long long free     = (long long)uv.free     << uv.pageshift;
+    long long active   = (long long)uv.active   << uv.pageshift;
+    long long inactive = (long long)uv.inactive << uv.pageshift;
+    long long wired    = (long long)uv.wired    << uv.pageshift;
+
+    /*
+     * cached: all memory currently backing file, exec, and anonymous
+     * mappings. Matches btop and the "Cached" line in /proc/meminfo.
+     */
+    long long cached = (long long)(uv.filepages + uv.execpages + uv.anonpages)
+                       << uv.pageshift;
+
+    /*
+     * buffers: file-backed pages excluding executable mappings.
+     * uvmexp_sysctl.filepages is the correct, always-synced source.
+     * Do NOT read this from /proc/meminfo "Buffers:" — that field is
+     * unreliable on NetBSD because procfs_domeminfo() reads cpu_counts[]
+     * without calling cpu_count_sync() first, producing stale values.
+     */
+    long long buffers = (long long)uv.filepages << uv.pageshift;
+
+    /*
+     * shared: virtual + real shared memory pages from vmtotal.
+     * This matches the "MemShared" line in /proc/meminfo.
+     */
+    long long shared = (long long)(vmdata.t_vmshr + vmdata.t_rmshr)
+                       << uv.pageshift;
 
-    // Note: zabbix does not include anonpages, but that doesn't match the
-    // "Cached" value in /proc/meminfo.
-    // https://github.com/zabbix/zabbix/blob/af5e0f8/src/libs/zbxsysinfo/netbsd/memory.c#L182
-    cached = (uv.filepages + uv.execpages + uv.anonpages) << uv.pageshift;
     return Py_BuildValue(
-        "LLLLLL",
-        (long long)uv.npages << uv.pageshift,  // total
-        (long long)uv.free << uv.pageshift,  // free
-        (long long)uv.active << uv.pageshift,  // active
-        (long long)uv.inactive << uv.pageshift,  // inactive
-        (long long)uv.wired << uv.pageshift,  // wired
-        cached  // cached
+        "LLLLLLLL",
+        total,     // total physical memory
+        free,      // free pages
+        active,    // active pages
+        inactive,  // inactive pages
+        wired,     // wired (kernel) pages
+        cached,    // file + exec + anon pages
+        buffers,   // file pages only (excl. exec)
+        shared     // shared memory pages
     );
 }
 
-
 PyObject *
 psutil_swap_mem(PyObject *self, PyObject *args) {
     uint64_t swap_total, swap_free;
