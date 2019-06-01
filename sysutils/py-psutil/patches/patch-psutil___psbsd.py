$NetBSD: patch-psutil___psbsd.py,v 1.3 2019/06/01 01:11:57 kamil Exp $

Use proc_cwd on NetBSD >= 8.99.42.

--- psutil/_psbsd.py.orig	2019-04-11 21:10:12.000000000 +0000
+++ psutil/_psbsd.py
@@ -105,6 +105,7 @@ HAS_PER_CPU_TIMES = hasattr(cext, "per_c
 HAS_PROC_NUM_THREADS = hasattr(cext, "proc_num_threads")
 HAS_PROC_OPEN_FILES = hasattr(cext, 'proc_open_files')
 HAS_PROC_NUM_FDS = hasattr(cext, 'proc_num_fds')
+HAS_PROC_CWD = hasattr(cext, 'proc_cwd')
 
 kinfo_proc_map = dict(
     ppid=0,
@@ -845,6 +846,8 @@ class Process(object):
         if OPENBSD and self.pid == 0:
             return None  # ...else it would raise EINVAL
         elif NETBSD:
+            if HAS_PROC_CWD:
+                return cext.proc_cwd(self.pid) or None
             with wrap_exceptions_procfs(self):
                 return os.readlink("/proc/%s/cwd" % self.pid)
         elif HAS_PROC_OPEN_FILES:
