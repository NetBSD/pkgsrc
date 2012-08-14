$NetBSD: patch-numpy_distutils_fcompiler_gnu.py,v 1.3 2012/08/14 20:19:21 fhajny Exp $

Do not run a shell command when it is "None".
Linker needs -shared explictly (at least with GCC 4.7 on SunOS).

--- numpy/distutils/fcompiler/gnu.py.orig	2011-03-11 05:56:15.000000000 +0000
+++ numpy/distutils/fcompiler/gnu.py
@@ -70,7 +70,7 @@ class GnuFCompiler(FCompiler):
         'compiler_f77' : [None, "-g", "-Wall", "-fno-second-underscore"],
         'compiler_f90' : None, # Use --fcompiler=gnu95 for f90 codes
         'compiler_fix' : None,
-        'linker_so'    : [None, "-g", "-Wall"],
+        'linker_so'    : [None, "-g", "-Wall", "-shared"],
         'archiver'     : ["ar", "-cr"],
         'ranlib'       : ["ranlib"],
         'linker_exe'   : [None, "-g", "-Wall"]
@@ -255,7 +255,7 @@ class Gnu95FCompiler(GnuFCompiler):
         'compiler_f90' : [None, "-Wall", "-fno-second-underscore"] + _EXTRAFLAGS,
         'compiler_fix' : [None, "-Wall", "-ffixed-form",
                           "-fno-second-underscore"] + _EXTRAFLAGS,
-        'linker_so'    : ["<F90>", "-Wall"],
+        'linker_so'    : ["<F90>", "-Wall", "-shared"],
         'archiver'     : ["ar", "-cr"],
         'ranlib'       : ["ranlib"],
         'linker_exe'   : [None, "-Wall"]
@@ -268,7 +268,7 @@ class Gnu95FCompiler(GnuFCompiler):
 
     def _universal_flags(self, cmd):
         """Return a list of -arch flags for every supported architecture."""
-        if not sys.platform == 'darwin':
+        if not sys.platform == 'darwin' or cmd == None:
             return []
         arch_flags = []
         # get arches the C compiler gets.
