$NetBSD: patch-psutil___psutil__netbsd.c,v 1.2 2015/01/24 23:01:29 adam Exp $

Port to NetBSD.

--- psutil/_psutil_netbsd.c.orig	2013-10-12 13:19:29.000000000 +0000
+++ psutil/_psutil_netbsd.c
@@ -0,0 +1,1307 @@
+/*
+ * Copyright (c) 2009, Giampaolo Rodola'. All rights reserved.
+ * Use of this source code is governed by a BSD-style license that can be
+ * found in the LICENSE file.
+ *
+ * NetBSD platform-specific module methods for _psutil_netbsd
+ */
+
+
+#include <Python.h>
+#include <assert.h>
+#include <errno.h>
+#include <stdlib.h>
+#include <stdio.h>
+#include <signal.h>
+#include <fcntl.h>
+#include <paths.h>
+#include <sys/types.h>
+#define _KMEMUSER 1           /* needed on NetBSD to get kprocinfo structs */
+#include <sys/sysctl.h>
+#include <sys/param.h>
+#include <sys/user.h>
+#include <sys/proc.h>
+#include <sys/file.h>
+#include <net/route.h>
+
+#include <sys/socket.h>
+#include <sys/socketvar.h>    /* for struct xsocket */
+/* for xinpcb struct */
+#include <netinet/in.h>
+#include <netinet/in_systm.h>
+#include <netinet/ip.h>
+#include <netinet/in_pcb.h>
+#include <netinet/tcp.h>       /* for tcp_seq type */
+#include <netinet/ip_var.h>    /* for struct ipqehead */
+#include <netinet/tcp_timer.h> /* for TCPT_NTIMERS */
+#include <netinet/tcp_var.h>   /* for struct xtcpcb */
+#include <netinet/tcp_fsm.h>   /* for TCP connection states */
+#include <arpa/inet.h>         /* for inet_ntop() */
+
+#include <utmpx.h>
+#include <kvm.h>
+#include <util.h>
+#include <sys/vmmeter.h>  /* needed for vmtotal struct */
+#include <sys/mount.h>
+
+#include <net/if.h>       /* net io counters */
+#include <net/if_dl.h>
+#include <net/route.h>
+
+#include <netinet/in.h>   /* process open files/connections */
+#include <sys/un.h>
+
+#include <stdbool.h>
+
+#include "_psutil_netbsd.h"
+#include "_psutil_common.h"
+#include "arch/bsd/process_info.h"
+
+#define STIME(k)	((k)->p_ustime_sec + (k)->p_ustime_usec/1000000.0)
+#define UTIME(k)	((k)->p_uutime_sec + (k)->p_uutime_usec/1000000.0)
+
+#if !defined(KERN_PROC_INC_THREAD)
+#define KERN_PROC_INC_THREAD 0
+#endif
+
+/* Determine whether and where procfs is mounted. */
+static bool
+psutil_find_procfs(char *buffer, size_t buffer_size)
+{
+    int num, i;
+    struct statvfs *mntbuf;
+
+    num = getmntinfo(&mntbuf, 0);
+    if (num == 0) {
+        return false;
+    }
+
+    for (i = 0; i < num; i++) {
+        if (strcmp(mntbuf[i].f_fstypename, "procfs") == 0) {
+            (void)strlcpy(buffer, mntbuf[i].f_mntonname, buffer_size);
+            return true;
+        }
+    }
+
+    errno = ENOENT;
+    return false;
+}
+
+/*
+ * Utility function which fills a struct kinfo_proc2 struct based on process pid
+ */
+static int
+psutil_get_kinfo_proc(const pid_t pid, struct kinfo_proc2 *proc)
+{
+    int mib[4];
+    size_t size;
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC2;
+    mib[2] = KERN_PROC_PID;
+    mib[3] = pid;
+
+    size = sizeof(struct kinfo_proc2);
+
+    if (sysctl((int*)mib, 4, proc, &size, NULL, 0) == -1) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        return -1;
+    }
+
+    /*
+     * sysctl stores 0 in the size if we can't find the process information.
+     */
+    if (size == 0) {
+        NoSuchProcess();
+        return -1;
+    }
+    return 0;
+}
+
+static int
+psutil_get_pagesize(void)
+{
+    int mib[2];
+    int pagesize;
+    size_t size;
+    mib[0] = CTL_HW;
+    mib[1] = HW_PAGESIZE;
+
+    size = sizeof(int);
+
+    if (sysctl((int*)mib, 2, &pagesize, &size, NULL, 0) == -1) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        return -1;
+    }
+
+    return pagesize;
+}
+
+
+/*
+ * Return a Python list of all the PIDs running on the system.
+ */
+static PyObject*
+get_pid_list(PyObject* self, PyObject* args)
+{
+    struct kinfo_proc2 *proclist = NULL;
+    struct kinfo_proc2 *orig_address = NULL;
+    size_t num_processes;
+    size_t idx;
+    PyObject* retlist = PyList_New(0);
+    PyObject* pid = NULL;
+
+    if (retlist == NULL) {
+        return NULL;
+    }
+    if (psutil_get_proc_list(&proclist, &num_processes) != 0) {
+        PyErr_SetString(PyExc_RuntimeError, "failed to retrieve process list.");
+        goto error;
+    }
+
+    if (num_processes > 0) {
+        orig_address = proclist; // save so we can free it after we're done
+        for (idx=0; idx < num_processes; idx++) {
+            pid = Py_BuildValue("i", proclist->p_pid);
+            if (!pid)
+                goto error;
+            if (PyList_Append(retlist, pid))
+                goto error;
+            Py_DECREF(pid);
+            proclist++;
+        }
+        free(orig_address);
+    }
+
+    return retlist;
+
+error:
+    Py_XDECREF(pid);
+    Py_DECREF(retlist);
+    if (orig_address != NULL) {
+        free(orig_address);
+    }
+    return NULL;
+}
+
+
+/*
+ * Return a Python float indicating the system boot time expressed in
+ * seconds since the epoch.
+ */
+static PyObject*
+get_system_boot_time(PyObject* self, PyObject* args)
+{
+    /* fetch sysctl "kern.boottime" */
+    static int request[2] = { CTL_KERN, KERN_BOOTTIME };
+    struct timeval boottime;
+    size_t len = sizeof(boottime);
+
+    if (sysctl(request, 2, &boottime, &len, NULL, 0) == -1) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        return NULL;
+    }
+    return Py_BuildValue("d", (double)boottime.tv_sec);
+}
+
+
+/*
+ * Return process name from struct kinfo_proc2 as a Python string.
+ */
+static PyObject*
+get_process_name(PyObject* self, PyObject* args)
+{
+    long pid;
+    struct kinfo_proc2 kp;
+    if (! PyArg_ParseTuple(args, "l", &pid)) {
+        return NULL;
+    }
+    if (psutil_get_kinfo_proc(pid, &kp) == -1) {
+        return NULL;
+    }
+    return Py_BuildValue("s", kp.p_comm);
+}
+
+
+/*
+ * Return process pathname executable.
+ * Thanks to Robert N. M. Watson:
+ * http://fxr.googlebit.com/source/usr.bin/procstat/procstat_bin.c?v=8-CURRENT
+ */
+static PyObject*
+get_process_exe(PyObject* self, PyObject* args)
+{
+    long pid;
+    char procfs[PATH_MAX], exelink[PATH_MAX], pathname[PATH_MAX];
+    ssize_t len;
+
+    if (! PyArg_ParseTuple(args, "l", &pid)) {
+        PyErr_BadArgument();
+        return NULL;
+    }
+
+    /* Is procfs mounted? */
+    if (! psutil_find_procfs(procfs, sizeof(procfs))) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        return NULL;
+    }
+
+    /* Get the name of the executable from procfs. */
+    (void)snprintf(exelink, sizeof(exelink), "%s/%ld/exe", procfs, pid);
+    len = readlink(exelink, pathname, sizeof(pathname) - 1);
+    if (len == - 1) {
+        if (errno == ENOENT) {
+            return NoSuchProcess();
+        } else {
+            PyErr_SetFromErrno(PyExc_OSError);
+            return NULL;
+        }
+    }
+    pathname[len] = '\0';
+
+    /*
+     * Does the link point to "/"? In this case procfs doesn't know where
+     * the executable is.
+     */
+    if (strcmp(pathname, "/") == 0) {
+        errno = ENOENT;
+        PyErr_SetFromErrno(PyExc_OSError);
+        return NULL;
+    }
+
+    return Py_BuildValue("s", pathname);
+}
+
+
+/*
+ * Return process cmdline as a Python list of cmdline arguments.
+ */
+static PyObject*
+get_process_cmdline(PyObject* self, PyObject* args)
+{
+    long pid;
+    PyObject* arglist = NULL;
+
+    if (! PyArg_ParseTuple(args, "l", &pid)) {
+        return NULL;
+    }
+
+    // get the commandline, defined in arch/bsd/process_info.c
+    arglist = psutil_get_arg_list(pid);
+
+    // psutil_get_arg_list() returns NULL only if psutil_get_cmd_args failed with ESRCH
+    // (no process with that PID)
+    if (NULL == arglist) {
+        return PyErr_SetFromErrno(PyExc_OSError);
+    }
+    return Py_BuildValue("N", arglist);
+}
+
+
+/*
+ * Return process parent pid from struct kinfo_proc2 as a Python integer.
+ */
+static PyObject*
+get_process_ppid(PyObject* self, PyObject* args)
+{
+    long pid;
+    struct kinfo_proc2 kp;
+    if (! PyArg_ParseTuple(args, "l", &pid)) {
+        return NULL;
+    }
+    if (psutil_get_kinfo_proc(pid, &kp) == -1) {
+        return NULL;
+    }
+    return Py_BuildValue("l", (long)kp.p_ppid);
+}
+
+
+/*
+ * Return process status as a Python integer.
+ */
+static PyObject*
+get_process_status(PyObject* self, PyObject* args)
+{
+    long pid;
+    struct kinfo_proc2 kp;
+    if (! PyArg_ParseTuple(args, "l", &pid)) {
+        return NULL;
+    }
+    if (psutil_get_kinfo_proc(pid, &kp) == -1) {
+        return NULL;
+    }
+    return Py_BuildValue("i", (int)kp.p_stat);
+}
+
+
+/*
+ * Return process real, effective and saved user ids from struct kinfo_proc2
+ * as a Python tuple.
+ */
+static PyObject*
+get_process_uids(PyObject* self, PyObject* args)
+{
+    long pid;
+    struct kinfo_proc2 kp;
+    if (! PyArg_ParseTuple(args, "l", &pid)) {
+        return NULL;
+    }
+    if (psutil_get_kinfo_proc(pid, &kp) == -1) {
+        return NULL;
+    }
+    return Py_BuildValue("lll", (long)kp.p_ruid,
+                                (long)kp.p_uid,
+                                (long)kp.p_svuid);
+}
+
+
+/*
+ * Return process real, effective and saved group ids from struct kinfo_proc2
+ * as a Python tuple.
+ */
+static PyObject*
+get_process_gids(PyObject* self, PyObject* args)
+{
+    long pid;
+    struct kinfo_proc2 kp;
+    if (! PyArg_ParseTuple(args, "l", &pid)) {
+        return NULL;
+    }
+    if (psutil_get_kinfo_proc(pid, &kp) == -1) {
+        return NULL;
+    }
+    return Py_BuildValue("lll", (long)kp.p_rgid,
+                                (long)kp.p_groups[0],
+                                (long)kp.p_svuid);
+}
+
+
+/*
+ * Return process real, effective and saved group ids from struct kinfo_proc2
+ * as a Python tuple.
+ */
+static PyObject*
+get_process_tty_nr(PyObject* self, PyObject* args)
+{
+    long pid;
+    struct kinfo_proc2 kp;
+    if (! PyArg_ParseTuple(args, "l", &pid)) {
+        return NULL;
+    }
+    if (psutil_get_kinfo_proc(pid, &kp) == -1) {
+        return NULL;
+    }
+    return Py_BuildValue("i", kp.p_tdev);
+}
+
+
+/*
+ * Return the number of context switches performed by process as a tuple.
+ */
+static PyObject*
+get_process_num_ctx_switches(PyObject* self, PyObject* args)
+{
+    long pid;
+    struct kinfo_proc2 kp;
+    if (! PyArg_ParseTuple(args, "l", &pid)) {
+        return NULL;
+    }
+    if (psutil_get_kinfo_proc(pid, &kp) == -1) {
+        return NULL;
+    }
+    return Py_BuildValue("(ll)", kp.p_uru_nvcsw,
+                                 kp.p_uru_nivcsw);
+}
+
+
+
+/*
+ * Return number of threads used by process as a Python integer.
+ */
+static PyObject*
+get_process_num_threads(PyObject* self, PyObject* args)
+{
+    long pid;
+    struct kinfo_proc2 kp;
+    if (! PyArg_ParseTuple(args, "l", &pid)) {
+        return NULL;
+    }
+    if (psutil_get_kinfo_proc(pid, &kp) == -1) {
+        return NULL;
+    }
+    return Py_BuildValue("l", (long)kp.p_nlwps);
+}
+
+
+/*
+ * Retrieves all threads used by process returning a list of tuples
+ * including thread id, user time and system time.
+ * Thanks to Robert N. M. Watson:
+ * http://fxr.googlebit.com/source/usr.bin/procstat/procstat_threads.c?v=8-CURRENT
+ */
+static PyObject*
+get_process_threads(PyObject* self, PyObject* args)
+{
+    long pid;
+    int mib[4];
+    struct kinfo_proc2 *kip = NULL;
+    struct kinfo_proc2 *kipp = NULL;
+    int error;
+    unsigned int i;
+    size_t size;
+    PyObject* retList = PyList_New(0);
+    PyObject* pyTuple = NULL;
+
+    if (retList == NULL)
+        return NULL;
+    if (! PyArg_ParseTuple(args, "l", &pid))
+        goto error;
+
+    /*
+     * We need to re-query for thread information, so don't use *kipp.
+     */
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_PID | KERN_PROC_INC_THREAD;
+    mib[3] = pid;
+
+    size = 0;
+    error = sysctl(mib, 4, NULL, &size, NULL, 0);
+    if (error == -1) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        goto error;
+    }
+    if (size == 0) {
+        NoSuchProcess();
+        goto error;
+    }
+
+    kip = malloc(size);
+    if (kip == NULL) {
+        PyErr_NoMemory();
+        goto error;
+    }
+
+    error = sysctl(mib, 4, kip, &size, NULL, 0);
+    if (error == -1) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        goto error;
+    }
+    if (size == 0) {
+        NoSuchProcess();
+        goto error;
+    }
+
+    for (i = 0; i < size / sizeof(*kipp); i++) {
+        kipp = &kip[i];
+        pyTuple = Py_BuildValue("Idd",
+				       /** \todo: unsupported? */
+         			       0, // kipp->ki_tid
+                                       UTIME(kipp),
+                                       STIME(kipp)
+                                );
+        if (pyTuple == NULL)
+            goto error;
+        if (PyList_Append(retList, pyTuple))
+            goto error;
+        Py_DECREF(pyTuple);
+    }
+    free(kip);
+
+    return retList;
+
+error:
+    Py_XDECREF(pyTuple);
+    Py_DECREF(retList);
+    if (kip != NULL) {
+        free(kip);
+    }
+    return NULL;
+}
+
+
+/*
+ * Return a Python tuple (user_time, kernel_time)
+ */
+static PyObject*
+get_process_cpu_times(PyObject* self, PyObject* args)
+{
+    long pid;
+    double user_t, sys_t;
+    struct kinfo_proc2 kp;
+    if (! PyArg_ParseTuple(args, "l", &pid)) {
+        return NULL;
+    }
+    if (psutil_get_kinfo_proc(pid, &kp) == -1) {
+        return NULL;
+    }
+    // convert from microseconds to seconds
+    user_t = UTIME(&kp);
+    sys_t = STIME(&kp);
+    return Py_BuildValue("(dd)", user_t, sys_t);
+}
+
+
+/*
+ * Return a Python integer indicating the number of CPUs on the system
+ */
+static PyObject*
+get_num_cpus(PyObject* self, PyObject* args)
+{
+    int mib[2];
+    int ncpu;
+    size_t len;
+
+    mib[0] = CTL_HW;
+    mib[1] = HW_NCPU;
+    len = sizeof(ncpu);
+
+    if (sysctl(mib, 2, &ncpu, &len, NULL, 0) == -1) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        return NULL;
+    }
+
+    return Py_BuildValue("i", ncpu);
+}
+
+
+/*
+ * Return a Python float indicating the process create time expressed in
+ * seconds since the epoch.
+ */
+static PyObject*
+get_process_create_time(PyObject* self, PyObject* args)
+{
+    /** \todo: implement */
+    return NULL;
+}
+
+
+/*
+ * Return a Python float indicating the process create time expressed in
+ * seconds since the epoch.
+ */
+static PyObject*
+get_process_io_counters(PyObject* self, PyObject* args)
+{
+    /** \todo: implement */
+    return NULL;
+}
+
+
+/*
+ * Return extended memory info for a process as a Python tuple.
+ */
+static PyObject*
+get_process_memory_info(PyObject* self, PyObject* args)
+{
+    int pagesize;
+    long pid;
+    struct kinfo_proc2 kp;
+    if (! PyArg_ParseTuple(args, "l", &pid)) {
+        return NULL;
+    }
+    if (psutil_get_kinfo_proc(pid, &kp) == -1) {
+        return NULL;
+    }
+    pagesize = psutil_get_pagesize();
+
+    /** \todo: find replacement for kp.ki_size */
+    return Py_BuildValue("(lllll)", kp.p_vm_rssize * pagesize,    // rss
+                                    0, //vms(long)kp.ki_size,     // vms
+                                    kp.p_vm_tsize * pagesize,     // text
+                                    kp.p_vm_dsize * pagesize,     // data
+                                    kp.p_vm_ssize * pagesize);    // stack
+}
+
+
+/*
+ * Return virtual memory usage statistics.
+ */
+static PyObject*
+get_virtual_mem(PyObject* self, PyObject* args)
+{
+    int                  mib[2];
+    struct uvmexp_sysctl uvmexp;
+    size_t               size;
+    struct vmtotal       vm;
+    int64_t              pagesize;
+
+    mib[0] = CTL_VM;
+    mib[1] = VM_UVMEXP2;
+    size = sizeof(uvmexp);
+    if (sysctl(mib, 2, &uvmexp, &size, NULL, 0) < 0)
+        goto error;
+
+    mib[0] = CTL_VM;
+    mib[1] = VM_METER;
+    size = sizeof(vm);
+    if (sysctl(mib, 2, &vm, &size, NULL, 0) != 0)
+        goto error;
+
+    pagesize = uvmexp.pagesize;
+    return Py_BuildValue("KKKKKK",
+        uvmexp.npages   * pagesize,
+        uvmexp.free     * pagesize,
+        uvmexp.active   * pagesize,
+        uvmexp.inactive * pagesize,
+        uvmexp.wired    * pagesize,
+        (vm.t_vmshr + vm.t_rmshr) * pagesize  // shared
+    );
+
+error:
+    PyErr_SetFromErrno(PyExc_OSError);
+    return NULL;
+}
+
+
+/*
+ * Return swap memory stats (see 'swapinfo' cmdline tool)
+ */
+static PyObject*
+get_swap_mem(PyObject* self, PyObject* args)
+{
+    /** \todo: implement; see sbin/swapctl/swaplist.c for possible example code */
+    return NULL;
+}
+
+
+/*
+ * Return a Python tuple representing user, kernel and idle CPU times
+ */
+static PyObject*
+get_system_cpu_times(PyObject* self, PyObject* args)
+{
+    long cpu_time[CPUSTATES];
+    size_t size;
+
+    size = sizeof(cpu_time);
+
+    if (sysctlbyname("kern.cp_time", &cpu_time, &size, NULL, 0) == -1) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        return NULL;
+    }
+
+    return Py_BuildValue("(ddddd)",
+                         (double)cpu_time[CP_USER] / CLOCKS_PER_SEC,
+                         (double)cpu_time[CP_NICE] / CLOCKS_PER_SEC,
+                         (double)cpu_time[CP_SYS] / CLOCKS_PER_SEC,
+                         (double)cpu_time[CP_IDLE] / CLOCKS_PER_SEC,
+                         (double)cpu_time[CP_INTR] / CLOCKS_PER_SEC
+    );
+}
+
+/*
+ * Return files opened by process as a list of (path, fd) tuples
+ */
+static PyObject*
+get_process_open_files(PyObject* self, PyObject* args)
+{
+    /** \todo: implement */
+    return NULL;
+}
+
+
+/*
+ * Return files opened by process as a list of (path, fd) tuples
+ */
+static PyObject*
+get_process_num_fds(PyObject* self, PyObject* args)
+{
+    /** \todo: implement */
+    return NULL;
+}
+
+
+/*
+ * Return process current working directory.
+ */
+static PyObject*
+get_process_cwd(PyObject* self, PyObject* args)
+{
+    /** \todo: implement */
+    return NULL;
+}
+
+
+static char *
+psutil_fetch_tcplist(void)
+{
+    /** \todo: implement */
+    return NULL;
+}
+
+static int
+psutil_sockaddr_port(int family, struct sockaddr_storage *ss)
+{
+    struct sockaddr_in6 *sin6;
+    struct sockaddr_in *sin;
+
+    if (family == AF_INET) {
+        sin = (struct sockaddr_in *)ss;
+        return (sin->sin_port);
+    } else {
+        sin6 = (struct sockaddr_in6 *)ss;
+        return (sin6->sin6_port);
+    }
+}
+
+static void *
+psutil_sockaddr_addr(int family, struct sockaddr_storage *ss)
+{
+    struct sockaddr_in6 *sin6;
+    struct sockaddr_in *sin;
+
+    if (family == AF_INET) {
+        sin = (struct sockaddr_in *)ss;
+        return (&sin->sin_addr);
+    } else {
+        sin6 = (struct sockaddr_in6 *)ss;
+        return (&sin6->sin6_addr);
+    }
+}
+
+static socklen_t
+psutil_sockaddr_addrlen(int family)
+{
+    if (family == AF_INET)
+        return (sizeof(struct in_addr));
+    else
+        return (sizeof(struct in6_addr));
+}
+
+static int
+psutil_sockaddr_matches(int family, int port, void *pcb_addr,
+                        struct sockaddr_storage *ss)
+{
+    if (psutil_sockaddr_port(family, ss) != port)
+        return (0);
+    return (memcmp(psutil_sockaddr_addr(family, ss), pcb_addr,
+        psutil_sockaddr_addrlen(family)) == 0);
+}
+
+static struct tcpcb *
+psutil_search_tcplist(char *buf, struct kinfo_file *kif)
+{
+    /** \todo: implement */
+    return NULL;
+}
+
+// a signaler for connections without an actual status
+static int PSUTIL_CONN_NONE = 128;
+
+/*
+ * Return connections opened by process.
+ */
+static PyObject*
+get_process_connections(PyObject* self, PyObject* args)
+{
+    /** \todo: implement */
+    return NULL;
+}
+
+
+/*
+ * Return a Python list of tuple representing per-cpu times
+ */
+static PyObject*
+get_system_per_cpu_times(PyObject* self, PyObject* args)
+{
+    int mib[2];
+    int ncpu;
+    size_t size;
+    int i;
+    PyObject* py_retlist = PyList_New(0);
+    PyObject* py_cputime = NULL;
+    long cpu_time[MAXCPUS][CPUSTATES];
+
+    if (py_retlist == NULL)
+        return NULL;
+
+    // retrieve the number of cpus
+    mib[0] = CTL_HW;
+    mib[1] = HW_NCPU;
+    size = sizeof(ncpu);
+    if (sysctl(mib, 2, &ncpu, &size, NULL, 0) == -1) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        goto error;
+    }
+
+    // per-cpu info
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_CP_TIME;
+    size = sizeof(cpu_time);
+    if (sysctl(mib, 2, cpu_time, &size, NULL, 0) == -1) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        goto error;
+    }
+
+    for (i = 0; i < ncpu; i++) {
+        py_cputime = Py_BuildValue("(ddddd)",
+                               (double)cpu_time[i][CP_USER] / CLOCKS_PER_SEC,
+                               (double)cpu_time[i][CP_NICE] / CLOCKS_PER_SEC,
+                               (double)cpu_time[i][CP_SYS] / CLOCKS_PER_SEC,
+                               (double)cpu_time[i][CP_IDLE] / CLOCKS_PER_SEC,
+                               (double)cpu_time[i][CP_INTR] / CLOCKS_PER_SEC
+                               );
+        if (!py_cputime)
+            goto error;
+        if (PyList_Append(py_retlist, py_cputime))
+            goto error;
+        Py_DECREF(py_cputime);
+    }
+
+    return py_retlist;
+
+error:
+    Py_XDECREF(py_cputime);
+    Py_DECREF(py_retlist);
+    return NULL;
+}
+
+
+// remove spaces from string
+void remove_spaces(char *str) {
+    char *p1 = str;
+    char *p2 = str;
+    do
+        while (*p2 == ' ')
+            p2++;
+    while (*p1++ = *p2++);
+}
+
+/*
+ * Return a list of tuples for every process memory maps.
+ * 'procstat' cmdline utility has been used as an example.
+ */
+static PyObject*
+get_process_memory_maps(PyObject* self, PyObject* args)
+{
+    /** \todo: implement */
+    return NULL;
+}
+
+
+/*
+ * Return a list of tuples including device, mount point and fs type
+ * for all partitions mounted on the system.
+ */
+static PyObject*
+get_disk_partitions(PyObject* self, PyObject* args)
+{
+    int num;
+    int i;
+    long len;
+    uint64_t flags;
+    char opts[200];
+    struct statvfs *fs = NULL;
+    PyObject* py_retlist = PyList_New(0);
+    PyObject* py_tuple = NULL;
+
+    if (py_retlist == NULL)
+        return NULL;
+
+    // get the number of mount points
+    Py_BEGIN_ALLOW_THREADS
+    num = getvfsstat(NULL, 0, MNT_NOWAIT);
+    Py_END_ALLOW_THREADS
+    if (num == -1) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        goto error;
+    }
+
+    len = sizeof(*fs) * num;
+    fs = malloc(len);
+    if (fs == NULL) {
+        PyErr_NoMemory();
+        goto error;
+    }
+
+    Py_BEGIN_ALLOW_THREADS
+    num = getvfsstat(fs, len, MNT_NOWAIT);
+    Py_END_ALLOW_THREADS
+    if (num == -1) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        goto error;
+    }
+
+    for (i = 0; i < num; i++) {
+        py_tuple = NULL;
+        opts[0] = 0;
+        flags = fs[i].f_flag;
+
+        // see sys/mount.h
+        if (flags & MNT_RDONLY)
+            strlcat(opts, "ro", sizeof(opts));
+        else
+            strlcat(opts, "rw", sizeof(opts));
+        if (flags & ST_NOEXEC)
+            strlcat(opts, ",noexec", sizeof(opts));
+        if (flags & ST_NOSUID)
+            strlcat(opts, ",nosuid", sizeof(opts));
+        if (flags & ST_NODEV)
+            strlcat(opts, ",nodev", sizeof(opts));
+        if (flags & ST_UNION)
+            strlcat(opts, ",union", sizeof(opts));
+        if (flags & ST_SYNCHRONOUS)
+            strlcat(opts, ",sync", sizeof(opts));
+        if (flags & ST_ASYNC)
+            strlcat(opts, ",async", sizeof(opts));
+        if (flags & ST_NOCOREDUMP)
+            strlcat(opts, ",nocoredump", sizeof(opts));
+        if (flags & ST_NOATIME)
+            strlcat(opts, ",noatime", sizeof(opts));
+        if (flags & ST_SYMPERM)
+            strlcat(opts, ",symperm", sizeof(opts));
+        if (flags & ST_NODEVMTIME)
+            strlcat(opts, ",nodevmtime", sizeof(opts));
+        if (flags & ST_LOG)
+            strlcat(opts, ",log", sizeof(opts));
+        if (flags & ST_LOCAL)
+            strlcat(opts, ",local", sizeof(opts));
+        if (flags & ST_QUOTA)
+            strlcat(opts, ",quota", sizeof(opts));
+        if (flags & ST_ROOTFS)
+            strlcat(opts, ",rootfs", sizeof(opts));
+        if (flags & ST_EXRDONLY)
+            strlcat(opts, ",exrdonly", sizeof(opts));
+        if (flags & ST_EXPORTED)
+            strlcat(opts, ",exported", sizeof(opts));
+        if (flags & ST_DEFEXPORTED)
+            strlcat(opts, ",defexported", sizeof(opts));
+        if (flags & ST_EXPORTANON)
+            strlcat(opts, ",exportanon", sizeof(opts));
+        if (flags & ST_EXKERB)
+            strlcat(opts, ",exkerb", sizeof(opts));
+        if (flags & ST_EXNORESPORT)
+            strlcat(opts, ",exnoresport", sizeof(opts));
+        if (flags & ST_EXPUBLIC)
+            strlcat(opts, ",expublic", sizeof(opts));
+
+        py_tuple = Py_BuildValue("(ssss)", fs[i].f_mntfromname,  // device
+                                           fs[i].f_mntonname,    // mount point
+                                           fs[i].f_fstypename,   // fs type
+                                           opts);                // options
+        if (!py_tuple)
+            goto error;
+        if (PyList_Append(py_retlist, py_tuple))
+            goto error;
+        Py_DECREF(py_tuple);
+    }
+
+    free(fs);
+    return py_retlist;
+
+error:
+    Py_XDECREF(py_tuple);
+    Py_DECREF(py_retlist);
+    if (fs != NULL)
+        free(fs);
+    return NULL;
+}
+
+
+/*
+ * Return a Python list of named tuples with overall network I/O information
+ */
+static PyObject*
+get_net_io_counters(PyObject* self, PyObject* args)
+{
+    char *buf = NULL, *lim, *next;
+    struct if_msghdr *ifm;
+    int mib[6];
+    size_t len;
+    PyObject* py_retdict = PyDict_New();
+    PyObject* py_ifc_info = NULL;
+    if (py_retdict == NULL)
+        return NULL;
+
+    mib[0] = CTL_NET;          // networking subsystem
+    mib[1] = PF_ROUTE;         // type of information
+    mib[2] = 0;                // protocol (IPPROTO_xxx)
+    mib[3] = 0;                // address family
+    mib[4] = NET_RT_IFLIST;   // operation
+    mib[5] = 0;
+
+    if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        goto error;
+    }
+
+    buf = malloc(len);
+    if (buf == NULL) {
+        PyErr_NoMemory();
+        goto error;
+    }
+
+    if (sysctl(mib, 6, buf, &len, NULL, 0) < 0) {
+        PyErr_SetFromErrno(PyExc_OSError);
+        goto error;
+    }
+
+    lim = buf + len;
+
+    for (next = buf; next < lim; ) {
+        py_ifc_info = NULL;
+        ifm = (struct if_msghdr *)next;
+        next += ifm->ifm_msglen;
+
+        if (ifm->ifm_type == RTM_IFINFO) {
+            struct if_msghdr *if2m = (struct if_msghdr *)ifm;
+            struct sockaddr_dl *sdl = (struct sockaddr_dl *)(if2m + 1);
+            char ifc_name[32];
+
+            strncpy(ifc_name, sdl->sdl_data, sdl->sdl_nlen);
+            ifc_name[sdl->sdl_nlen] = 0;
+            // XXX: ignore usbus interfaces:
+            // http://lists.freebsd.org/pipermail/freebsd-current/2011-October/028752.html
+            // 'ifconfig -a' doesn't show them, nor do we.
+            if (strncmp(ifc_name, "usbus", 5) == 0) {
+                continue;
+            }
+
+            py_ifc_info = Py_BuildValue("(kkkkkkki)",
+                                        if2m->ifm_data.ifi_obytes,
+                                        if2m->ifm_data.ifi_ibytes,
+                                        if2m->ifm_data.ifi_opackets,
+                                        if2m->ifm_data.ifi_ipackets,
+                                        if2m->ifm_data.ifi_ierrors,
+                                        if2m->ifm_data.ifi_oerrors,
+                                        if2m->ifm_data.ifi_iqdrops,
+                                        0);  // dropout not supported
+            if (!py_ifc_info)
+                goto error;
+            if (PyDict_SetItemString(py_retdict, ifc_name, py_ifc_info))
+                goto error;
+            Py_DECREF(py_ifc_info);
+        }
+        else {
+            continue;
+        }
+    }
+
+    free(buf);
+    return py_retdict;
+
+error:
+    Py_XDECREF(py_ifc_info);
+    Py_DECREF(py_retdict);
+    if (buf != NULL)
+        free(buf);
+    return NULL;
+}
+
+
+/*
+ * Return a Python dict of tuples for disk I/O information
+ */
+static PyObject*
+get_disk_io_counters(PyObject* self, PyObject* args)
+{
+    /** \todo: not implemented */
+    return NULL;
+}
+
+
+/*
+ * Return currently connected users as a list of tuples.
+ */
+static PyObject*
+get_system_users(PyObject* self, PyObject* args)
+{
+    PyObject *ret_list = PyList_New(0);
+    PyObject *tuple = NULL;
+
+    if (ret_list == NULL)
+        return NULL;
+
+    struct utmpx *utx;
+
+    while ((utx = getutxent()) != NULL) {
+        if (utx->ut_type != USER_PROCESS)
+            continue;
+        tuple = Py_BuildValue("(sssf)",
+            utx->ut_user,             // username
+            utx->ut_line,             // tty
+            utx->ut_host,             // hostname
+            (float)utx->ut_tv.tv_sec  // start time
+        );
+        if (!tuple) {
+            endutxent();
+            goto error;
+        }
+        if (PyList_Append(ret_list, tuple)) {
+            endutxent();
+            goto error;
+        }
+        Py_DECREF(tuple);
+    }
+
+    endutxent();
+    return ret_list;
+
+error:
+    Py_XDECREF(tuple);
+    Py_DECREF(ret_list);
+    return NULL;
+}
+
+
+/*
+ * define the psutil C module methods and initialize the module.
+ */
+static PyMethodDef
+PsutilMethods[] =
+{
+     // --- per-process functions
+
+     {"get_process_name", get_process_name, METH_VARARGS,
+        "Return process name"},
+     {"get_process_connections", get_process_connections, METH_VARARGS,
+        "Return connections opened by process"},
+     {"get_process_exe", get_process_exe, METH_VARARGS,
+        "Return process pathname executable"},
+     {"get_process_cmdline", get_process_cmdline, METH_VARARGS,
+        "Return process cmdline as a list of cmdline arguments"},
+     {"get_process_ppid", get_process_ppid, METH_VARARGS,
+        "Return process ppid as an integer"},
+     {"get_process_uids", get_process_uids, METH_VARARGS,
+        "Return process real effective and saved user ids as a Python tuple"},
+     {"get_process_gids", get_process_gids, METH_VARARGS,
+        "Return process real effective and saved group ids as a Python tuple"},
+     {"get_process_cpu_times", get_process_cpu_times, METH_VARARGS,
+           "Return tuple of user/kern time for the given PID"},
+     {"get_process_create_time", get_process_create_time, METH_VARARGS,
+         "Return a float indicating the process create time expressed in "
+         "seconds since the epoch"},
+     {"get_process_memory_info", get_process_memory_info, METH_VARARGS,
+         "Return extended memory info for a process as a Python tuple."},
+     {"get_process_num_threads", get_process_num_threads, METH_VARARGS,
+         "Return number of threads used by process"},
+     {"get_process_num_ctx_switches", get_process_num_ctx_switches, METH_VARARGS,
+         "Return the number of context switches performed by process"},
+     {"get_process_threads", get_process_threads, METH_VARARGS,
+         "Return process threads"},
+     {"get_process_status", get_process_status, METH_VARARGS,
+         "Return process status as an integer"},
+     {"get_process_io_counters", get_process_io_counters, METH_VARARGS,
+         "Return process IO counters"},
+     {"get_process_tty_nr", get_process_tty_nr, METH_VARARGS,
+         "Return process tty (terminal) number"},
+     {"get_process_open_files", get_process_open_files, METH_VARARGS,
+         "Return files opened by process as a list of (path, fd) tuples"},
+     {"get_process_cwd", get_process_cwd, METH_VARARGS,
+         "Return process current working directory."},
+     {"get_process_memory_maps", get_process_memory_maps, METH_VARARGS,
+         "Return a list of tuples for every process's memory map"},
+     {"get_process_num_fds", get_process_num_fds, METH_VARARGS,
+         "Return the number of file descriptors opened by this process"},
+
+     // --- system-related functions
+
+     {"get_pid_list", get_pid_list, METH_VARARGS,
+         "Returns a list of PIDs currently running on the system"},
+     {"get_num_cpus", get_num_cpus, METH_VARARGS,
+           "Return number of CPUs on the system"},
+     {"get_virtual_mem", get_virtual_mem, METH_VARARGS,
+         "Return system virtual memory usage statistics"},
+     {"get_swap_mem", get_swap_mem, METH_VARARGS,
+         "Return swap mem stats"},
+     {"get_system_cpu_times", get_system_cpu_times, METH_VARARGS,
+         "Return system cpu times as a tuple (user, system, nice, idle, irc)"},
+     {"get_system_per_cpu_times", get_system_per_cpu_times, METH_VARARGS,
+         "Return system per-cpu times as a list of tuples"},
+     {"get_system_boot_time", get_system_boot_time, METH_VARARGS,
+         "Return the system boot time expressed in seconds since the epoch."},
+     {"get_disk_partitions", get_disk_partitions, METH_VARARGS,
+         "Return a list of tuples including device, mount point and "
+         "fs type for all partitions mounted on the system."},
+     {"get_net_io_counters", get_net_io_counters, METH_VARARGS,
+         "Return dict of tuples of networks I/O information."},
+     {"get_disk_io_counters", get_disk_io_counters, METH_VARARGS,
+         "Return a Python dict of tuples for disk I/O information"},
+     {"get_system_users", get_system_users, METH_VARARGS,
+        "Return currently connected users as a list of tuples"},
+
+     {NULL, NULL, 0, NULL}
+};
+
+struct module_state {
+    PyObject *error;
+};
+
+#if PY_MAJOR_VERSION >= 3
+#define GETSTATE(m) ((struct module_state*)PyModule_GetState(m))
+#else
+#define GETSTATE(m) (&_state)
+#endif
+
+#if PY_MAJOR_VERSION >= 3
+
+static int
+psutil_netbsd_traverse(PyObject *m, visitproc visit, void *arg) {
+    Py_VISIT(GETSTATE(m)->error);
+    return 0;
+}
+
+static int
+psutil_netbsd_clear(PyObject *m) {
+    Py_CLEAR(GETSTATE(m)->error);
+    return 0;
+}
+
+static struct PyModuleDef
+moduledef = {
+        PyModuleDef_HEAD_INIT,
+        "psutil_netbsd",
+        NULL,
+        sizeof(struct module_state),
+        PsutilMethods,
+        NULL,
+        psutil_netbsd_traverse,
+        psutil_netbsd_clear,
+        NULL
+};
+
+#define INITERROR return NULL
+
+PyObject *
+PyInit__psutil_netbsd(void)
+
+#else
+#define INITERROR return
+
+void init_psutil_netbsd(void)
+#endif
+{
+#if PY_MAJOR_VERSION >= 3
+    PyObject *module = PyModule_Create(&moduledef);
+#else
+    PyObject *module = Py_InitModule("_psutil_netbsd", PsutilMethods);
+#endif
+    // process status constants
+    PyModule_AddIntConstant(module, "SIDL", SIDL);
+    PyModule_AddIntConstant(module, "SACTIVE", SACTIVE);
+    PyModule_AddIntConstant(module, "SDYING", SDYING);
+    PyModule_AddIntConstant(module, "SSTOP", SSTOP);
+    PyModule_AddIntConstant(module, "SZOMB", SZOMB);
+    PyModule_AddIntConstant(module, "SDEAD", SDEAD);
+    // connection status constants
+    PyModule_AddIntConstant(module, "TCPS_CLOSED", TCPS_CLOSED);
+    PyModule_AddIntConstant(module, "TCPS_CLOSING", TCPS_CLOSING);
+    PyModule_AddIntConstant(module, "TCPS_CLOSE_WAIT", TCPS_CLOSE_WAIT);
+    PyModule_AddIntConstant(module, "TCPS_LISTEN", TCPS_LISTEN);
+    PyModule_AddIntConstant(module, "TCPS_ESTABLISHED", TCPS_ESTABLISHED);
+    PyModule_AddIntConstant(module, "TCPS_SYN_SENT", TCPS_SYN_SENT);
+    PyModule_AddIntConstant(module, "TCPS_SYN_RECEIVED", TCPS_SYN_RECEIVED);
+    PyModule_AddIntConstant(module, "TCPS_FIN_WAIT_1", TCPS_FIN_WAIT_1);
+    PyModule_AddIntConstant(module, "TCPS_FIN_WAIT_2", TCPS_FIN_WAIT_2);
+    PyModule_AddIntConstant(module, "TCPS_LAST_ACK", TCPS_LAST_ACK);
+    PyModule_AddIntConstant(module, "TCPS_TIME_WAIT", TCPS_TIME_WAIT);
+
+    if (module == NULL) {
+        INITERROR;
+    }
+#if PY_MAJOR_VERSION >= 3
+    return module;
+#endif
+}
