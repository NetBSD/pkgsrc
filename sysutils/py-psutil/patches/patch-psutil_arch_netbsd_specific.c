$NetBSD: patch-psutil_arch_netbsd_specific.c,v 1.4 2019/06/11 22:55:04 leot Exp $

Use proc_cwd on NetBSD >= 8.99.42.

--- psutil/arch/netbsd/specific.c.orig	2019-03-02 20:46:28.000000000 +0000
+++ psutil/arch/netbsd/specific.c
@@ -112,6 +112,24 @@ kinfo_getfile(pid_t pid, int* cnt) {
     return kf;
 }
 
+#ifdef KERN_PROC_CWD /* Introduced in NetBSD-8.99.42 */
+PyObject *
+psutil_proc_cwd(PyObject *self, PyObject *args) {
+    long pid;
+    char path[MAXPATHLEN];
+    size_t pathlen = sizeof path;
+
+    if (! PyArg_ParseTuple(args, "l", &pid))
+        return NULL;
+    
+    int name[] = { CTL_KERN, KERN_PROC_ARGS, pid, KERN_PROC_CWD};
+    if (sysctl(name, 4, path, &pathlen, NULL, 0) != 0) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        return NULL;
+    }
+    return PyUnicode_DecodeFSDefault(path);
+}
+#endif
 
 // XXX: This is no longer used as per
 // https://github.com/giampaolo/psutil/pull/557#issuecomment-171912820
