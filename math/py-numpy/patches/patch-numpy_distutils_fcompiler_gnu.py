$NetBSD: patch-numpy_distutils_fcompiler_gnu.py,v 1.15 2020/03/26 08:33:36 jperkin Exp $

Linker needs -shared explictly (at least with GCC 4.7 on SunOS), plus
any ABI flags as appropriate.
Do not generate debug symbols (remove '-g').
On OS X, do not use '-bundle' and 'dynamic_lookup' (to avoid Python.framework).
Do not use -funroll-loops compiler flag.
Do not run a shell command when it is "None".

--- numpy/distutils/fcompiler/gnu.py.orig	2018-04-23 16:28:56.000000000 +0000
+++ numpy/distutils/fcompiler/gnu.py
@@ -63,8 +63,10 @@ class GnuFCompiler(FCompiler):
                     return ('gfortran', m.group(1))
         else:
             # Output probably from --version, try harder:
-            m = re.search(r'GNU Fortran\s+95.*?([0-9-.]+)', version_string)
+            m = re.search(r'95.*?([0-9-.]+)', version_string)
             if m:
+                if m.group(1).split(".") < ["4", "2"]:
+                    self.g2c = "f95"
                 return ('gfortran', m.group(1))
             m = re.search(
                 r'GNU Fortran.*?\-?([0-9-.]+\.[0-9-.]+)', version_string)
@@ -91,13 +93,13 @@ class GnuFCompiler(FCompiler):
     possible_executables = ['g77', 'f77']
     executables = {
         'version_cmd'  : [None, "-dumpversion"],
-        'compiler_f77' : [None, "-g", "-Wall", "-fno-second-underscore"],
+        'compiler_f77' : [None, "-Wall", "-fno-second-underscore"],
         'compiler_f90' : None,  # Use --fcompiler=gnu95 for f90 codes
         'compiler_fix' : None,
-        'linker_so'    : [None, "-g", "-Wall"],
+        'linker_so'    : [None, "-Wall", "-shared"],
         'archiver'     : ["ar", "-cr"],
         'ranlib'       : ["ranlib"],
-        'linker_exe'   : [None, "-g", "-Wall"]
+        'linker_exe'   : [None, "-Wall"]
     }
     module_dir_switch = None
     module_include_switch = None
@@ -146,7 +148,7 @@ class GnuFCompiler(FCompiler):
                     s = 'Env. variable MACOSX_DEPLOYMENT_TARGET set to 10.3'
                     warnings.warn(s, stacklevel=2)
 
-            opt.extend(['-undefined', 'dynamic_lookup', '-bundle'])
+            opt.extend(['-undefined'])
         else:
             opt.append("-shared")
         if sys.platform.startswith('sunos'):
@@ -237,7 +239,6 @@ class GnuFCompiler(FCompiler):
             opt = ['-O2']
         else:
             opt = ['-O3']
-        opt.append('-funroll-loops')
         return opt
 
     def _c_arch_flags(self):
@@ -288,13 +289,13 @@ class Gnu95FCompiler(GnuFCompiler):
     possible_executables = ['gfortran', 'f95']
     executables = {
         'version_cmd'  : ["<F90>", "-dumpversion"],
-        'compiler_f77' : [None, "-Wall", "-g", "-ffixed-form",
+        'compiler_f77' : [None, "-Wall", "-ffixed-form",
                           "-fno-second-underscore"] + _EXTRAFLAGS,
-        'compiler_f90' : [None, "-Wall", "-g",
+        'compiler_f90' : [None, "-Wall",
                           "-fno-second-underscore"] + _EXTRAFLAGS,
-        'compiler_fix' : [None, "-Wall",  "-g","-ffixed-form",
+        'compiler_fix' : [None, "-Wall",  "-ffixed-form",
                           "-fno-second-underscore"] + _EXTRAFLAGS,
-        'linker_so'    : ["<F90>", "-Wall", "-g"],
+        'linker_so'    : ["<F90>", "-Wall", "-shared"],
         'archiver'     : ["ar", "-cr"],
         'ranlib'       : ["ranlib"],
         'linker_exe'   : [None, "-Wall"]
@@ -307,7 +308,7 @@ class Gnu95FCompiler(GnuFCompiler):
 
     def _universal_flags(self, cmd):
         """Return a list of -arch flags for every supported architecture."""
-        if not sys.platform == 'darwin':
+        if not sys.platform == 'darwin' or cmd is None:
             return []
         arch_flags = []
         # get arches the C compiler gets.
