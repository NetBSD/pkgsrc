$NetBSD: patch-mypy_util.py,v 1.1 2026/10/05 07:37:32 wiz Exp $

Avoid using non-existent psutil functionality.
https://github.com/python/mypy/issues/22103

--- mypy/util.py.orig	2026-10-05 07:29:49.089700218 +0000
+++ mypy/util.py
@@ -1009,7 +1009,7 @@ def get_available_threads() -> int:
     # Not available on old Python versions on some platforms.
     if sys.platform == "linux":
         affinity = os.sched_getaffinity(0)
-    if PSUTIL_AVAILABLE and sys.platform != "darwin":
+    if PSUTIL_AVAILABLE and (psutil.LINUX or psutil.WINDOWS or psutil.FREEBSD):
         # Currently not supported on macOS.
         affinity = psutil.Process().cpu_affinity()
 
