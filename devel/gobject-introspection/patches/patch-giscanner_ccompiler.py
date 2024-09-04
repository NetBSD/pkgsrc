$NetBSD: patch-giscanner_ccompiler.py,v 1.8 2024/09/04 06:05:05 prlw1 Exp $

Fix build with py-setuptools-74.0.0. (upstream a2139dba59)
Exclude system paths from LD_LIBRARY_PATH.
Do not use -Wl,--no-as-needed on SunOS.

--- giscanner/ccompiler.py.orig	2024-04-01 13:21:25.000000000 +0000
+++ giscanner/ccompiler.py
@@ -26,7 +26,6 @@ import tempfile
 import sys
 import distutils
 
-from distutils.msvccompiler import MSVCCompiler
 from distutils.unixccompiler import UnixCCompiler
 from distutils.cygwinccompiler import Mingw32CCompiler
 from distutils.sysconfig import get_config_vars
@@ -167,7 +166,7 @@ class CCompiler(object):
         # Now, create the distutils ccompiler instance based on the info we have.
         if compiler_name == 'msvc':
             # For MSVC, we need to create a instance of a subclass of distutil's
-            # MSVC9Compiler class, as it does not provide a preprocess()
+            # MSVCCompiler class, as it does not provide a preprocess()
             # implementation
             from . import msvccompiler
             self.compiler = msvccompiler.get_msvc_compiler()
@@ -232,7 +231,7 @@ class CCompiler(object):
 
                 # Ensure libraries are always linked as we are going to use ldd to work
                 # out their names later
-                if sys.platform != 'darwin':
+                if sys.platform != 'darwin' and sys.platform != 'sunos5':
                     args.append('-Wl,--no-as-needed')
 
         for library_path in libpaths:
@@ -250,7 +249,8 @@ class CCompiler(object):
                     else:
                         args.append('-Wl,-rpath,' + library_path)
 
-            runtime_paths.append(library_path)
+            if library_path not in '@_OPSYS_LIB_DIRS@'.split(' '):
+                runtime_paths.append(library_path)
 
         for library in libraries + extra_libraries:
             if os.path.isfile(library):
@@ -460,7 +460,7 @@ class CCompiler(object):
             return self.compiler.linker_exe
 
     def check_is_msvc(self):
-        return isinstance(self.compiler, MSVCCompiler)
+        return self.compiler.compiler_type == "msvc"
 
     # Private APIs
     def _set_cpp_options(self, options):
@@ -486,7 +486,7 @@ class CCompiler(object):
                     # macros for compiling using distutils
                     # get dropped for MSVC builds, so
                     # escape the escape character.
-                    if isinstance(self.compiler, MSVCCompiler):
+                    if self.check_is_msvc():
                         macro_value = macro_value.replace('\"', '\\\"')
                 macros.append((macro_name, macro_value))
             elif option.startswith('-U'):
