$NetBSD: patch-psutil_arch_netbsd_cpu.c,v 1.5 2026/04/07 05:49:12 fox Exp $

Remove dependency on procfs.

Upstream: https://github.com/giampaolo/psutil/pull/2805

--- psutil/arch/netbsd/cpu.c.orig	2025-11-06 17:44:47.000000000 +0000
+++ psutil/arch/netbsd/cpu.c
@@ -22,7 +22,6 @@ original(ish) implementations:
 - CPU stats: a991494e4502e1235ebc62b5ba450287d0dedec0 (Jan 2016)
 */
 
-
 PyObject *
 psutil_cpu_stats(PyObject *self, PyObject *args) {
     struct uvmexp_sysctl uv;
@@ -30,15 +29,16 @@ psutil_cpu_stats(PyObject *self, PyObjec
 
     if (psutil_sysctl(uvmexp_mib, 2, &uv, sizeof(uv)) != 0)
         return NULL;
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
+        (uint64_t)uv.intrs,    // interrupts (summed across CPUs by sysctl handler)
+        (uint64_t)uv.softs,    // soft interrupts
+        (uint64_t)uv.syscalls, // syscalls - XXX always 0
+        (uint64_t)uv.traps,    // traps
+        (uint64_t)uv.faults,   // faults
+        (uint64_t)uv.forks     // forks
     );
 }
 
