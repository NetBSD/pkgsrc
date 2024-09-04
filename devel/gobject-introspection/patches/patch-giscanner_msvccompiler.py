$NetBSD: patch-giscanner_msvccompiler.py,v 1.1 2024/09/04 06:05:05 prlw1 Exp $

Fix build with py-setuptools-74.0.0. (upstream a2139dba59)

--- giscanner/msvccompiler.py.orig	2024-04-01 13:21:25.000000000 +0000
+++ giscanner/msvccompiler.py
@@ -19,30 +19,30 @@
 #
 
 import os
-import distutils
+from typing import Type
 
 from distutils.errors import DistutilsExecError, CompileError
-from distutils.ccompiler import CCompiler, gen_preprocess_options
+from distutils.ccompiler import CCompiler, gen_preprocess_options, new_compiler
 from distutils.dep_util import newer
 
 # Distutil's MSVCCompiler does not provide a preprocess()
 # Implementation, so do our own here.
 
 
+DistutilsMSVCCompiler: Type = type(new_compiler(compiler="msvc"))
+
+
 def get_msvc_compiler():
     return MSVCCompiler()
 
 
-class MSVCCompiler(distutils.msvccompiler.MSVCCompiler):
+class MSVCCompiler(DistutilsMSVCCompiler):
 
     def __init__(self, verbose=0, dry_run=0, force=0):
-        super(distutils.msvccompiler.MSVCCompiler, self).__init__()
+	super(DistutilsMSVCCompiler, self).__init__()
         CCompiler.__init__(self, verbose, dry_run, force)
         self.__paths = []
         self.__arch = None  # deprecated name
-        if os.name == 'nt':
-            if isinstance(self, distutils.msvc9compiler.MSVCCompiler):
-                self.__version = distutils.msvc9compiler.VERSION
         self.initialized = False
         self.preprocess_options = None
         if self.check_is_clang_cl():
