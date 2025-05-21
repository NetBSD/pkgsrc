$NetBSD: patch-joblib_externals_loky_backend_context.py,v 1.2 2025/05/21 07:05:30 adam Exp $

Add BSD support.

--- joblib/externals/loky/backend/context.py.orig	2025-05-03 21:09:12.000000000 +0000
+++ joblib/externals/loky/backend/context.py
@@ -240,6 +240,9 @@ def _count_physical_cores():
         return physical_cores_cache, exception
 
     # Not cached yet, find it
+    # Using subprocesses is inefficient, but python has no portable
+    # sysctl interface at this time
+    # FIXME: Add OpenBSD, Dragonfly
     try:
         if sys.platform == "linux":
             cpu_count_physical = _count_physical_cores_linux()
@@ -247,6 +250,26 @@ def _count_physical_cores():
             cpu_count_physical = _count_physical_cores_win32()
         elif sys.platform == "darwin":
             cpu_count_physical = _count_physical_cores_darwin()
+        elif sys.platform.startswith('freebsd'):
+            cpu_info = subprocess.run(
+                "sysctl -n kern.smp.cores".split(),
+                capture_output=True,
+                text=True,
+            )
+            cpu_info = cpu_info.stdout
+            cpu_count_physical = int(cpu_info)
+        elif sys.platform.startswith('netbsd'):
+            # FIXME: hw.ncpu reports the number of hyperthreads.
+            # We prefer independent cores to prevent oversubscription.
+            # NetBSD does not currently expose physical core counts,
+            # but this is under discussion in PR kern/57816.
+            cpu_info = subprocess.run(
+                "sysctl -n hw.ncpu".split(),
+                capture_output=True,
+                text=True,
+            )
+            cpu_info = cpu_info.stdout
+            cpu_count_physical = int(cpu_info)
         else:
             raise NotImplementedError(f"unsupported platform: {sys.platform}")
 
