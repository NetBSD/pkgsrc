$NetBSD: patch-numpy_distutils_fcompiler_gnu.py,v 1.8 2016/07/24 15:25:22 kamil Exp $

Linker needs -shared explictly (at least with GCC 4.7 on SunOS), plus
any ABI flags as appropriate.
On OS X, do not use '-bundle' and 'dynamic_lookup' (to avoid Python.framework).
Do not run a shell command when it is "None".

--- numpy/distutils/fcompiler/gnu.py.orig	2016-06-25 15:38:34.000000000 +0000
+++ numpy/distutils/fcompiler/gnu.py
@@ -57,7 +57,7 @@ class GnuFCompiler(FCompiler):
                     return ('gfortran', m.group(1))
         else:
             # Output probably from --version, try harder:
-            m = re.search(r'GNU Fortran\s+95.*?([0-9-.]+)', version_string)
+            m = re.search(r'95.*?([0-9-.]+)', version_string)
             if m:
                 return ('gfortran', m.group(1))
             m = re.search(r'GNU Fortran.*?\-?([0-9-.]+)', version_string)
@@ -87,7 +87,7 @@ class GnuFCompiler(FCompiler):
         'compiler_f77' : [None, "-g", "-Wall", "-fno-second-underscore"],
         'compiler_f90' : None,  # Use --fcompiler=gnu95 for f90 codes
         'compiler_fix' : None,
-        'linker_so'    : [None, "-g", "-Wall"],
+        'linker_so'    : [None, "-g", "-Wall", "-shared", ""],
         'archiver'     : ["ar", "-cr"],
         'ranlib'       : ["ranlib"],
         'linker_exe'   : [None, "-g", "-Wall"]
@@ -134,7 +134,7 @@ class GnuFCompiler(FCompiler):
                     s = 'Env. variable MACOSX_DEPLOYMENT_TARGET set to 10.3'
                     warnings.warn(s)
 
-            opt.extend(['-undefined', 'dynamic_lookup', '-bundle'])
+            opt.extend(['-undefined'])
         else:
             opt.append("-shared")
         if sys.platform.startswith('sunos'):
@@ -263,7 +263,7 @@ class Gnu95FCompiler(GnuFCompiler):
                           "-fno-second-underscore"] + _EXTRAFLAGS,
         'compiler_fix' : [None, "-Wall",  "-g","-ffixed-form",
                           "-fno-second-underscore"] + _EXTRAFLAGS,
-        'linker_so'    : ["<F90>", "-Wall", "-g"],
+        'linker_so'    : ["<F90>", "-Wall", "-g", "-shared", ""],
         'archiver'     : ["ar", "-cr"],
         'ranlib'       : ["ranlib"],
         'linker_exe'   : [None, "-Wall"]
@@ -276,7 +276,7 @@ class Gnu95FCompiler(GnuFCompiler):
 
     def _universal_flags(self, cmd):
         """Return a list of -arch flags for every supported architecture."""
-        if not sys.platform == 'darwin':
+        if not sys.platform == 'darwin' or cmd==None:
             return []
         arch_flags = []
         # get arches the C compiler gets.
