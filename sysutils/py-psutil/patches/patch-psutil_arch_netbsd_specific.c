$NetBSD: patch-psutil_arch_netbsd_specific.c,v 1.6 2022/08/02 17:13:10 wiz Exp $

Fix swap code.
https://github.com/giampaolo/psutil/pull/2128

--- psutil/arch/netbsd/specific.c.orig	2022-02-01 21:23:36.000000000 +0000
+++ psutil/arch/netbsd/specific.c
@@ -459,7 +459,7 @@ psutil_virtual_mem(PyObject *self, PyObj
         (unsigned long long) uv.active << uv.pageshift,  // active
         (unsigned long long) uv.inactive << uv.pageshift,  // inactive
         (unsigned long long) uv.wired << uv.pageshift,  // wired
-        (unsigned long long) uv.filepages + uv.execpages * pagesize,  // cached
+        (unsigned long long) (uv.filepages + uv.execpages) * pagesize,  // cached
         // These are determined from /proc/meminfo in Python.
         (unsigned long long) 0,  // buffers
         (unsigned long long) 0  // shared
@@ -495,8 +495,8 @@ psutil_swap_mem(PyObject *self, PyObject
     swap_total = swap_free = 0;
     for (i = 0; i < nswap; i++) {
         if (swdev[i].se_flags & SWF_ENABLE) {
-            swap_total += swdev[i].se_nblks * DEV_BSIZE;
-            swap_free += (swdev[i].se_nblks - swdev[i].se_inuse) * DEV_BSIZE;
+            swap_total += (uint64_t)swdev[i].se_nblks * DEV_BSIZE;
+            swap_free += (uint64_t)(swdev[i].se_nblks - swdev[i].se_inuse) * DEV_BSIZE;
         }
     }
     free(swdev);
