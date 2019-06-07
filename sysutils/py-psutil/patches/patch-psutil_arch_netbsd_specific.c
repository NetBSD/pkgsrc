$NetBSD: patch-psutil_arch_netbsd_specific.c,v 1.3 2019/06/07 19:09:06 leot Exp $

Don't include <sys/user.h> on NetBSD. Include <sys/iostat.h> instead.

Use proc_cwd on NetBSD >= 8.99.42.

Use an `int' to store `kern.argmax' to avoid possible read of
uninitialized memory.

--- psutil/arch/netbsd/specific.c.orig	2019-03-02 20:46:28.000000000 +0000
+++ psutil/arch/netbsd/specific.c
@@ -22,7 +22,7 @@
 #include <sys/types.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
-#include <sys/user.h>
+#include <sys/iostat.h>
 #include <sys/proc.h>
 #include <sys/swap.h>  // for swap_mem
 #include <signal.h>
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
@@ -313,8 +331,8 @@ psutil_get_proc_list(kinfo_proc **procLi
 char *
 psutil_get_cmd_args(pid_t pid, size_t *argsize) {
     int mib[4];
+    int argmax;
     ssize_t st;
-    size_t argmax;
     size_t size;
     char *procargs = NULL;
 
@@ -339,14 +357,15 @@ psutil_get_cmd_args(pid_t pid, size_t *a
     mib[2] = pid;
     mib[3] = KERN_PROC_ARGV;
 
-    st = sysctl(mib, 4, procargs, &argmax, NULL, 0);
+    size = argmax;
+    st = sysctl(mib, 4, procargs, &size, NULL, 0);
     if (st == -1) {
         free(procargs);
         PyErr_SetFromErrno(PyExc_OSError);
         return NULL;
     }
 
-    *argsize = argmax;
+    *argsize = size;
     return procargs;
 }
 
