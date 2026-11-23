$NetBSD: patch-src_shellingham_posix_proc.py,v 1.2 2026/11/23 13:22:33 wiz Exp $

Avoid using Linux procfs on NetBSD.
https://github.com/sarugaku/shellingham/issues/99

--- src/shellingham/posix/proc.py.orig	2023-10-24 01:51:22.000000000 +0000
+++ src/shellingham/posix/proc.py
@@ -6,7 +6,7 @@ from ._core import Process
 from ._core import Process
 
 # FreeBSD: https://www.freebsd.org/cgi/man.cgi?query=procfs
-# NetBSD: https://man.netbsd.org/NetBSD-9.3-STABLE/mount_procfs.8
+# NetBSD: https://man.netbsd.org/mount_procfs.8
 # DragonFlyBSD: https://www.dragonflybsd.org/cgi/web-man?command=procfs
 BSD_STAT_PPID = 2
 
@@ -26,9 +26,12 @@ def detect_proc():
     * `status`: BSD-style, i.e. ``/proc/{pid}/status``.
     """
     pid = os.getpid()
-    for name in ("stat", "status"):
-        if os.path.exists(os.path.join("/proc", str(pid), name)):
-            return name
+    if _use_bsd_stat_format():
+        if os.path.exists(os.path.join("/proc", str(pid), "status")):
+            return "status"
+    else:
+        if os.path.exists(os.path.join("/proc", str(pid), "stat")):
+            return "stat"
     raise ProcFormatError("unsupported proc format")
 
 
