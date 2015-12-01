$NetBSD: patch-psutil___psbsd.py,v 1.1 2015/12/01 14:07:36 ryoon Exp $

--- psutil/_psbsd.py.orig	2015-11-25 01:20:34.000000000 +0000
+++ psutil/_psbsd.py
@@ -28,6 +28,7 @@ __extra__all__ = []
 
 FREEBSD = sys.platform.startswith("freebsd")
 OPENBSD = sys.platform.startswith("openbsd")
+NETBSD = sys.platform.startswith("netbsd")
 
 if FREEBSD:
     PROC_STATUSES = {
@@ -60,6 +61,15 @@ elif OPENBSD:
         cext.SRUN: _common.STATUS_WAKING,
         cext.SONPROC: _common.STATUS_RUNNING,
     }
+elif NETBSD:
+    PROC_STATUSES = {
+        cext.SIDL: _common.STATUS_IDLE,
+        cext.SACTIVE: _common.STATUS_RUNNING,
+        cext.SDYING: _common.STATUS_ZOMBIE,
+        cext.SSTOP: _common.STATUS_STOPPED,
+        cext.SZOMB: _common.STATUS_ZOMBIE,
+        cext.SDEAD: _common.STATUS_DEAD,
+    }
 
 TCP_STATUSES = {
     cext.TCPS_ESTABLISHED: _common.CONN_ESTABLISHED,
@@ -76,7 +86,10 @@ TCP_STATUSES = {
     cext.PSUTIL_CONN_NONE: _common.CONN_NONE,
 }
 
-PAGESIZE = os.sysconf("SC_PAGE_SIZE")
+if NETBSD:
+    PAGESIZE = os.sysconf("SC_PAGESIZE")
+else:
+    PAGESIZE = os.sysconf("SC_PAGE_SIZE")
 AF_LINK = cext_posix.AF_LINK
 
 # extend base mem ntuple with BSD-specific memory metrics
@@ -156,9 +169,9 @@ def cpu_count_logical():
     return cext.cpu_count_logical()
 
 
-if OPENBSD:
+if OPENBSD or NETBSD:
     def cpu_count_physical():
-        # OpenBSD does not implement this.
+        # OpenBSD and NetBSD do not implement this.
         return 1 if cpu_count_logical() == 1 else None
 else:
     def cpu_count_physical():
@@ -273,7 +286,7 @@ def net_if_stats():
     return ret
 
 
-if OPENBSD:
+if OPENBSD or NETBSD:
     def pid_exists(pid):
         exists = _psposix.pid_exists(pid)
         if not exists:
@@ -333,7 +346,7 @@ class Process(object):
 
     @wrap_exceptions
     def exe(self):
-        if FREEBSD:
+        if FREEBSD or NETBSD:
             return cext.proc_exe(self.pid)
         else:
             # exe cannot be determined on OpenBSD; references:
@@ -423,6 +436,23 @@ class Process(object):
 
     @wrap_exceptions
     def connections(self, kind='inet'):
+        if NETBSD:
+            families, types = conn_tmap[kind]
+            ret = set()
+            rawlist = cext.proc_connections(self.pid)
+            for item in rawlist:
+                fd, fam, type, laddr, raddr, status = item
+                if fam in families and type in types:
+                    try:
+                        status = TCP_STATUSES[status]
+                    except KeyError:
+                        status = TCP_STATUSES[cext.PSUTIL_CONN_NONE]
+                    fam = sockfam_to_enum(fam)
+                    type = socktype_to_enum(type)
+                    nt = _common.pconn(fd, fam, type, laddr, raddr, status)
+                    ret.add(nt)
+            return list(ret)
+
         if kind not in conn_tmap:
             raise ValueError("invalid %r kind argument; choose between %s"
                              % (kind, ', '.join([repr(x) for x in conn_tmap])))
