$NetBSD: patch-mesonbuild_dependencies_dev.py,v 1.1 2019/10/04 14:06:19 prlw1 Exp $

Allow handling different versions of LLVM in pkgsrc using LLVM_CONFIG_PATH.

--- mesonbuild/dependencies/dev.py.orig	2019-07-09 16:34:42.000000000 +0000
+++ mesonbuild/dependencies/dev.py
@@ -212,21 +212,24 @@ class LLVMDependencyConfigTool(ConfigToo
         # newest back to oldest (3.5 is arbitrary), and finally the devel version.
         # Please note that llvm-config-6.0 is a development snapshot and it should
         # not be moved to the beginning of the list.
-        self.tools = [
-            'llvm-config', # base
-            'llvm-config-8',   'llvm-config80',
-            'llvm-config-7',   'llvm-config70',
-            'llvm-config-6.0', 'llvm-config60',
-            'llvm-config-5.0', 'llvm-config50',
-            'llvm-config-4.0', 'llvm-config40',
-            'llvm-config-3.9', 'llvm-config39',
-            'llvm-config-3.8', 'llvm-config38',
-            'llvm-config-3.7', 'llvm-config37',
-            'llvm-config-3.6', 'llvm-config36',
-            'llvm-config-3.5', 'llvm-config35',
-            'llvm-config-9',     # Debian development snapshot
-            'llvm-config-devel', # FreeBSD development snapshot
-        ]
+        if 'LLVM_CONFIG_PATH' in os.environ:
+            self.tools = [ os.environ['LLVM_CONFIG_PATH'] ]
+        else:
+            self.tools = [
+                'llvm-config', # base
+                'llvm-config-8',   'llvm-config80',
+                'llvm-config-7',   'llvm-config70',
+                'llvm-config-6.0', 'llvm-config60',
+                'llvm-config-5.0', 'llvm-config50',
+                'llvm-config-4.0', 'llvm-config40',
+                'llvm-config-3.9', 'llvm-config39',
+                'llvm-config-3.8', 'llvm-config38',
+                'llvm-config-3.7', 'llvm-config37',
+                'llvm-config-3.6', 'llvm-config36',
+                'llvm-config-3.5', 'llvm-config35',
+                'llvm-config-9',     # Debian development snapshot
+                'llvm-config-devel', # FreeBSD development snapshot
+            ]
 
         # Fedora starting with Fedora 30 adds a suffix of the number
         # of bits in the isa that llvm targets, for example, on x86_64
