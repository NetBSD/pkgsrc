$NetBSD: patch-psutil_arch_netbsd_specific.h,v 1.1 2019/06/01 01:11:57 kamil Exp $

Use proc_cwd on NetBSD >= 8.99.42.

--- psutil/arch/netbsd/specific.h.orig	2019-03-02 20:46:28.000000000 +0000
+++ psutil/arch/netbsd/specific.h
@@ -26,3 +26,6 @@ PyObject* psutil_disk_io_counters(PyObje
 PyObject* psutil_proc_exe(PyObject* self, PyObject* args);
 PyObject* psutil_proc_num_threads(PyObject* self, PyObject* args);
 PyObject* psutil_cpu_stats(PyObject* self, PyObject* args);
+#if (__NetBSD_Version__ - 0) >= 899004200
+PyObject *psutil_proc_cwd(PyObject *self, PyObject *args);
+#endif
