$NetBSD: patch-mesonbuild_compilers_compilers.py,v 1.2 2018/09/02 15:20:02 wiz Exp $

Support SunOS-specific GCC behaviour.
Limit GNU ld options correctly.

--- mesonbuild/compilers/compilers.py.orig	2018-06-22 11:50:56.000000000 +0000
+++ mesonbuild/compilers/compilers.py
@@ -172,6 +172,14 @@ arm_buildtype_linker_args = {'plain': []
                              'minsize': [],
                              }
 
+sunos_buildtype_linker_args = {'plain': [],
+                                 'debug': [],
+                                 'debugoptimized': [],
+                                 'release': [],
+                                 'minsize': [],
+                                 }
+
+
 msvc_buildtype_linker_args = {'plain': [],
                               'debug': [],
                               'debugoptimized': [],
@@ -1034,7 +1042,7 @@ class Compiler:
             # linked against local libraries will fail to resolve them.
             args.append('-Wl,-z,origin')
         args.append('-Wl,-rpath,' + paths)
-        if get_compiler_is_linuxlike(self):
+        if get_compiler_uses_gnuld(self):
             # Rpaths to use while linking must be absolute. These are not
             # written to the binary. Needed only with GNU ld:
             # https://sourceware.org/bugzilla/show_bug.cgi?id=16936
@@ -1066,6 +1074,7 @@ GCC_STANDARD = 0
 GCC_OSX = 1
 GCC_MINGW = 2
 GCC_CYGWIN = 3
+GCC_SUNOS = 4
 
 CLANG_STANDARD = 0
 CLANG_OSX = 1
@@ -1095,7 +1104,7 @@ def get_gcc_soname_args(gcc_type, prefix
         sostr = ''
     else:
         sostr = '.' + soversion
-    if gcc_type == GCC_STANDARD:
+    if gcc_type in (GCC_STANDARD, GCC_SUNOS):
         return ['-Wl,-soname,%s%s.%s%s' % (prefix, shlib_name, suffix, sostr)]
     elif gcc_type in (GCC_MINGW, GCC_CYGWIN):
         # For PE/COFF the soname argument has no effect with GNU LD
@@ -1236,6 +1245,8 @@ class GnuCompiler:
     def get_buildtype_linker_args(self, buildtype):
         if self.gcc_type == GCC_OSX:
             return apple_buildtype_linker_args[buildtype]
+        elif self.gcc_type == GCC_SUNOS:
+            return sunos_buildtype_linker_args[buildtype]
         return gnulike_buildtype_linker_args[buildtype]
 
     def get_pch_suffix(self):
