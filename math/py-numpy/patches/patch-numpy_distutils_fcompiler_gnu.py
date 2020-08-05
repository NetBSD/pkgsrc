$NetBSD: patch-numpy_distutils_fcompiler_gnu.py,v 1.17 2020/08/05 14:05:46 adam Exp $

Linker needs -shared explictly (at least with GCC 4.7 on SunOS), plus
any ABI flags as appropriate.
Do not generate debug symbols (remove '-g').
On Darwin, do not use '-bundle' (to avoid Python.framework).
Do not use -funroll-loops compiler flag.
Do not run a shell command when it is "None".

--- numpy/distutils/fcompiler/gnu.py.orig	2020-07-10 04:52:40.000000000 +0000
+++ numpy/distutils/fcompiler/gnu.py
@@ -60,8 +60,10 @@ class GnuFCompiler(FCompiler):
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
@@ -88,13 +90,13 @@ class GnuFCompiler(FCompiler):
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
@@ -134,7 +136,7 @@ class GnuFCompiler(FCompiler):
                     s = f'Env. variable MACOSX_DEPLOYMENT_TARGET set to {target}'
                     warnings.warn(s, stacklevel=2)
                 os.environ['MACOSX_DEPLOYMENT_TARGET'] = target
-            opt.extend(['-undefined', 'dynamic_lookup', '-bundle'])
+            opt.extend(['-undefined', 'dynamic_lookup'])
         else:
             opt.append("-shared")
         if sys.platform.startswith('sunos'):
@@ -233,7 +235,6 @@ class GnuFCompiler(FCompiler):
             opt = ['-O2']
         else:
             opt = ['-O3']
-        opt.append('-funroll-loops')
         return opt
 
     def _c_arch_flags(self):
@@ -296,13 +297,13 @@ class Gnu95FCompiler(GnuFCompiler):
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
@@ -321,7 +322,7 @@ class Gnu95FCompiler(GnuFCompiler):
 
     def _universal_flags(self, cmd):
         """Return a list of -arch flags for every supported architecture."""
-        if not sys.platform == 'darwin':
+        if not sys.platform == 'darwin' or cmd is None:
             return []
         arch_flags = []
         # get arches the C compiler gets.
