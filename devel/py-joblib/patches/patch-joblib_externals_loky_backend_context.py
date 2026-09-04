$NetBSD: patch-joblib_externals_loky_backend_context.py,v 1.3 2026/09/04 05:25:36 adam Exp $

Add BSD support.

--- joblib/externals/loky/backend/context.py.orig	2026-08-31 09:38:25.925587200 +0000
+++ joblib/externals/loky/backend/context.py
@@ -255,6 +255,9 @@ def _count_physical_cores():
         return physical_cores_cache, exception
 
     # Not cached yet, find it
+    # Using subprocesses is inefficient, but python has no portable
+    # sysctl interface at this time
+    # FIXME: Add OpenBSD, Dragonfly
     try:
         if sys.platform == "linux":
             cpu_count_physical = _count_physical_cores_linux()
@@ -264,6 +267,8 @@ def _count_physical_cores():
             cpu_count_physical = _count_physical_cores_darwin()
         elif sys.platform.startswith("freebsd"):
             cpu_count_physical = _count_physical_cores_freebsd()
+        elif sys.platform.startswith("netbsd"):
+            cpu_count_physical = _count_physical_cores_netbsd()
         else:
             raise NotImplementedError(f"unsupported platform: {sys.platform}")
 
@@ -430,6 +435,20 @@ def _count_physical_cores_freebsd():
     return int(cpu_info)
 
 
+# FIXME: hw.ncpu reports the number of hyperthreads.
+# We prefer independent cores to prevent oversubscription.
+# NetBSD does not currently expose physical core counts,
+# but this is under discussion in PR kern/57816.
+def _count_physical_cores_netbsd():
+    cpu_info = subprocess.run(
+        "sysctl -n hw.ncpu".split(),
+        capture_output=True,
+        text=True,
+    )
+    cpu_info = cpu_info.stdout
+    return int(cpu_info)
+
+
 class LokyContext(BaseContext):
     """Context relying on the LokyProcess."""
 
