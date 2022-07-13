$NetBSD: patch-mesonbuild_dependencies_dev.py,v 1.6 2022/07/13 03:57:22 triaxx Exp $

Allow handling different versions of LLVM in pkgsrc using LLVM_CONFIG_PATH.

--- mesonbuild/dependencies/dev.py.orig	2021-08-18 11:22:33.000000000 +0000
+++ mesonbuild/dependencies/dev.py
@@ -208,7 +208,10 @@ class LLVMDependencyConfigTool(ConfigToo
     __cpp_blacklist = {'-DNDEBUG'}
 
     def __init__(self, name: str, environment: 'Environment', kwargs: T.Dict[str, T.Any]):
-        self.tools = get_llvm_tool_names('llvm-config')
+        if 'LLVM_CONFIG_PATH' in os.environ:
+            self.tools = [os.environ['LLVM_CONFIG_PATH']]
+        else:
+            self.tools = get_llvm_tool_names('llvm-config')
 
         # Fedora starting with Fedora 30 adds a suffix of the number
         # of bits in the isa that llvm targets, for example, on x86_64
