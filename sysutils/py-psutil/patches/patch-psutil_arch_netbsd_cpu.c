$NetBSD: patch-psutil_arch_netbsd_cpu.c,v 1.4 2026/04/06 16:53:12 fox Exp $

Remove dependency on procfs.

Upstream: https://github.com/giampaolo/psutil/pull/2805

--- psutil/arch/netbsd/cpu.c.orig	2025-11-06 17:44:47.000000000 +0000
+++ psutil/arch/netbsd/cpu.c
@@ -6,6 +6,10 @@
  */
 
 #include <Python.h>
+#include <fcntl.h>
+#include <kvm.h>
+#include <limits.h>
+#include <nlist.h>
 #include <sys/sched.h>
 #include <sys/sysctl.h>
 #include <uvm/uvm_extern.h>
@@ -20,25 +24,59 @@ already) from cset 84219ad. For referenc
 original(ish) implementations:
 - per CPU times: 312442ad2a5b5d0c608476c5ab3e267735c3bc59 (Jan 2016)
 - CPU stats: a991494e4502e1235ebc62b5ba450287d0dedec0 (Jan 2016)
-*/
-
 
+Interrupts are now taken by reading the kvm_open and reading
+the CPU counter there. We no longer need /proc/stat dependency.
+- https://github.com/NetBSD/src/blob/trunk/sys/miscfs/procfs/procfs_linux.c#L342
+*/
 PyObject *
 psutil_cpu_stats(PyObject *self, PyObject *args) {
     struct uvmexp_sysctl uv;
     int uvmexp_mib[] = {CTL_VM, VM_UVMEXP2};
+    const int cpu_count_nintr = 3;
+    char errbuf[_POSIX2_LINE_MAX];
 
     if (psutil_sysctl(uvmexp_mib, 2, &uv, sizeof(uv)) != 0)
         return NULL;
+
+    kvm_t *kd = kvm_open(NULL, NULL, NULL, O_RDONLY, errbuf);
+    if (!kd) {
+        fprintf(stderr, "kvm_open: %s\n", errbuf);
+        return NULL;
+    }
+
+    struct nlist nl[] = {
+        { .n_name = "_cpu_counts" },
+        { .n_name = NULL          }
+    };
+
+    if (kvm_nlist(kd, nl) != 0 || nl[0].n_value == 0) {
+        fprintf(stderr, "kvm_nlist(_cpu_counts): %s\n", kvm_geterr(kd));
+        kvm_close(kd);
+        return NULL;
+    }
+
+    /* Read cpu_counts[CPU_COUNT_NINTR] — a single int64_t */
+    uintptr_t addr = nl[0].n_value + cpu_count_nintr * sizeof(int64_t);
+    int64_t nintr = 0;
+
+    if (kvm_read(kd, addr, &nintr, sizeof(nintr)) != sizeof(nintr)) {
+        fprintf(stderr, "kvm_read(cpu_counts[NINTR]): %s\n", kvm_geterr(kd));
+        kvm_close(kd);
+        return NULL;
+    }
+
+    kvm_close(kd);
+
     return Py_BuildValue(
-        "IIIIIII",
-        uv.swtch,  // ctx switches
-        uv.intrs,  // interrupts - XXX always 0, will be determined via /proc
-        uv.softs,  // soft interrupts
-        uv.syscalls,  // syscalls - XXX always 0
-        uv.traps,  // traps
-        uv.faults,  // faults
-        uv.forks  // forks
+        "KKKKKKK",
+        (uint64_t)uv.swtch,    // ctx switches
+        (uint64_t)nintr,        // interrupts
+        (uint64_t)uv.softs,    // soft interrupts
+        (uint64_t)uv.syscalls, // syscalls - XXX always 0
+        (uint64_t)uv.traps,    // traps
+        (uint64_t)uv.faults,   // faults
+        (uint64_t)uv.forks     // forks
     );
 }
 
