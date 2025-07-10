$NetBSD: patch-gprproject_gprbuild.py,v 1.1 2025/07/10 18:52:41 dkazankov Exp $

Fix duplicate gprconfig call

--- gprproject/gprbuild.py.orig	2024-09-24 12:28:32.000000000 +0300
+++ gprproject/gprbuild.py
@@ -59,8 +59,14 @@
         gprconfig_cmd = [which("gprconfig"), "--config=ada", "--mi-show-compilers"]
         if self.original_target:
             gprconfig_cmd.append(f"--target={self.original_target}")
-        gprconfig_output = self.capture(gprconfig_cmd)
-        self.target = re.findall(r" 1 normalized_target:(\S*)", gprconfig_output)[0]
+
+        if not target or not prefix:
+            gprconfig_output = self.capture(gprconfig_cmd)
+
+        if target:
+            self.target = target
+        else:
+            self.target = re.findall(r" 1 normalized_target:(\S*)", gprconfig_output)[0]
 
         # Compute default prefix
         if prefix:
@@ -84,9 +90,10 @@
 
         self.gnatcov = gnatcov
         self.symcc = symcc
-        self.gpr_paths: list[str] = []
-        if self.gpr_paths:
-            self.gpr_paths = list(gpr_paths)
+        self.gpr_paths = gpr_paths
+        if gpr_paths:
+            if type(gpr_paths) is str:
+                self.gpr_paths: list[str] = gpr_paths.split(",")
         else:
             self.gpr_paths = []
 
