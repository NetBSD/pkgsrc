$NetBSD: patch-mesonbuild_dependencies_dev.py,v 1.2 2019/10/18 09:59:46 nia Exp $

Allow handling different versions of LLVM in pkgsrc using LLVM_CONFIG_PATH.

--- mesonbuild/dependencies/dev.py.orig	2019-10-06 17:01:35.000000000 +0000
+++ mesonbuild/dependencies/dev.py
@@ -209,7 +209,10 @@ class LLVMDependencyConfigTool(ConfigToo
         # before `super().__init__` is called.
         HasNativeKwarg.__init__(self, kwargs)
 
-        self.tools = get_llvm_tool_names('llvm-config')
+        if 'LLVM_CONFIG_PATH' in os.environ:
+            self.tools = [ os.environ['LLVM_CONFIG_PATH'] ]
+        else:
+            self.tools = get_llvm_tool_names('llvm-config')
 
         # Fedora starting with Fedora 30 adds a suffix of the number
         # of bits in the isa that llvm targets, for example, on x86_64
