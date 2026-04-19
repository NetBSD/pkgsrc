$NetBSD: patch-mesonbuild_dependencies_dev.py,v 1.8 2026/04/19 17:14:21 wiz Exp $

Allow handling different versions of LLVM in pkgsrc using LLVM_CONFIG_PATH.

--- mesonbuild/dependencies/dev.py.orig	2026-04-13 14:03:15.000000000 +0000
+++ mesonbuild/dependencies/dev.py
@@ -192,7 +192,10 @@ class LLVMDependencyConfigTool(ConfigToolDependency):
 
     def __init__(self, name: str, environment: 'Environment', kwargs: DependencyObjectKWs):
         kwargs['language'] = 'cpp'
-        self.tools = get_llvm_tool_names('llvm-config')
+        if 'LLVM_CONFIG_PATH' in os.environ:
+            self.tools = [os.environ['LLVM_CONFIG_PATH']]
+        else:
+            self.tools = get_llvm_tool_names('llvm-config')
 
         # Fedora starting with Fedora 30 adds a suffix of the number
         # of bits in the isa that llvm targets, for example, on x86_64
