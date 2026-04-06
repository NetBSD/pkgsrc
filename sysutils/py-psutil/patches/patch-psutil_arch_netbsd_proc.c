$NetBSD: patch-psutil_arch_netbsd_proc.c,v 1.1 2026/04/06 16:53:12 fox Exp $

Handle EBUSY failures gracefully.

Upstream: https://github.com/giampaolo/psutil/pull/2805

--- psutil/arch/netbsd/proc.c.orig	2025-11-02 21:47:52.000000000 +0000
+++ psutil/arch/netbsd/proc.c
@@ -227,6 +227,7 @@ psutil_proc_cmdline(PyObject *self, PyOb
             if (errno == EBUSY) {
                 // Usually happens with TestProcess.test_long_cmdline. See:
                 // https://github.com/giampaolo/psutil/issues/2250
+	        PyErr_Clear();
                 attempt += 1;
                 if (attempt < max_attempts) {
                     psutil_debug("proc %zu cmdline(): retry on EBUSY", pid);
@@ -236,6 +237,7 @@ psutil_proc_cmdline(PyObject *self, PyOb
                     psutil_debug(
                         "proc %zu cmdline(): return [] due to EBUSY", pid
                     );
+		    PyErr_Clear();
                     return py_retlist;
                 }
             }
@@ -257,6 +259,7 @@ psutil_proc_cmdline(PyObject *self, PyOb
     }
 
     free(procargs);
+    PyErr_Clear();
     return py_retlist;
 
 error:
