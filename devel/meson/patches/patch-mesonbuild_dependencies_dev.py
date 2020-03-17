$NetBSD: patch-mesonbuild_dependencies_dev.py,v 1.3 2020/03/17 10:25:39 adam Exp $

Allow handling different versions of LLVM in pkgsrc using LLVM_CONFIG_PATH.

--- mesonbuild/dependencies/dev.py.orig	2020-01-23 12:51:19.000000000 +0000
+++ mesonbuild/dependencies/dev.py
@@ -205,7 +205,10 @@ class LLVMDependencyConfigTool(ConfigToo
     __cpp_blacklist = {'-DNDEBUG'}
 
     def __init__(self, environment, kwargs):
-        self.tools = get_llvm_tool_names('llvm-config')
+        if 'LLVM_CONFIG_PATH' in os.environ:
+            self.tools = [os.environ['LLVM_CONFIG_PATH']]
+        else:
+            self.tools = get_llvm_tool_names('llvm-config')
 
         # Fedora starting with Fedora 30 adds a suffix of the number
         # of bits in the isa that llvm targets, for example, on x86_64
