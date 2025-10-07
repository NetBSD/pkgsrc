$NetBSD: patch-core_gnatcoll__core.gpr.py,v 1.1 2025/10/07 20:45:10 dkazankov Exp $

Add NetBSD support

--- core/gnatcoll_core.gpr.py.orig	2024-09-24 12:28:32.000000000 +0300
+++ core/gnatcoll_core.gpr.py
@@ -40,6 +40,8 @@
         # Compute which implementation should be used for blake3
         if gpr.target in ("x86_64-linux", "aarch64-linux", "x86_64-windows"):
             blake3_arch = gpr.target
+        elif gpr.target in ("x86_64-netbsd"):
+            blake3_arch = "x86_64-linux"
         else:
             blake3_arch = "generic"
 
@@ -47,7 +49,7 @@
         gpr.set_variable("GNATCOLL_BLAKE3_ARCH", blake3_arch)
 
         # Compute which implementation should be used for xxhash
-        if gpr.target in ("x86_64-linux", "x86_64-windows"):
+        if gpr.target in ("x86_64-linux", "x86_64-windows", "x86_64-netbsd"):
             xxhash_arch = "x86_64"
         else:
             xxhash_arch = "generic"
