$NetBSD: patch-mesonbuild_dependencies_dev.py,v 1.7 2025/12/20 22:49:17 wiz Exp $

Allow handling different versions of LLVM in pkgsrc using LLVM_CONFIG_PATH.

--- mesonbuild/dependencies/dev.py.orig	2025-12-08 16:48:27.000000000 +0000
+++ mesonbuild/dependencies/dev.py
@@ -188,7 +188,10 @@ class LLVMDependencyConfigTool(ConfigToo
     __cpp_blacklist = {'-DNDEBUG'}
 
     def __init__(self, name: str, environment: 'Environment', kwargs: DependencyObjectKWs):
-        self.tools = get_llvm_tool_names('llvm-config')
+        if 'LLVM_CONFIG_PATH' in os.environ:
+            self.tools = [os.environ['LLVM_CONFIG_PATH']]
+        else:
+            self.tools = get_llvm_tool_names('llvm-config')
 
         # Fedora starting with Fedora 30 adds a suffix of the number
         # of bits in the isa that llvm targets, for example, on x86_64
