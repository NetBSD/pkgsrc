$NetBSD: patch-mesonbuild_compilers_compilers.py,v 1.1 2018/05/15 09:04:37 jperkin Exp $

Support SunOS-specific GCC behaviour.
Limit GNU ld options correctly.

--- mesonbuild/compilers/compilers.py.orig	2018-02-20 21:48:57.000000000 +0000
+++ mesonbuild/compilers/compilers.py
@@ -134,6 +134,14 @@ gnulike_buildtype_linker_args = {'plain'
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
@@ -853,7 +861,7 @@ class Compiler:
             else:
                 paths = paths + ':' + padding
         args = ['-Wl,-rpath,' + paths]
-        if get_compiler_is_linuxlike(self):
+        if get_compiler_uses_gnuld(self):
             # Rpaths to use while linking must be absolute. These are not
             # written to the binary. Needed only with GNU ld:
             # https://sourceware.org/bugzilla/show_bug.cgi?id=16936
@@ -876,6 +884,7 @@ GCC_STANDARD = 0
 GCC_OSX = 1
 GCC_MINGW = 2
 GCC_CYGWIN = 3
+GCC_SUNOS = 4
 
 CLANG_STANDARD = 0
 CLANG_OSX = 1
@@ -891,7 +900,7 @@ def get_gcc_soname_args(gcc_type, prefix
         sostr = ''
     else:
         sostr = '.' + soversion
-    if gcc_type in (GCC_STANDARD, GCC_MINGW, GCC_CYGWIN):
+    if gcc_type in (GCC_STANDARD, GCC_MINGW, GCC_CYGWIN, GCC_SUNOS):
         # Might not be correct for mingw but seems to work.
         return ['-Wl,-soname,%s%s.%s%s' % (prefix, shlib_name, suffix, sostr)]
     elif gcc_type == GCC_OSX:
@@ -1023,6 +1032,8 @@ class GnuCompiler:
     def get_buildtype_linker_args(self, buildtype):
         if self.gcc_type == GCC_OSX:
             return apple_buildtype_linker_args[buildtype]
+        elif self.gcc_type == GCC_SUNOS:
+            return sunos_buildtype_linker_args[buildtype]
         return gnulike_buildtype_linker_args[buildtype]
 
     def get_pch_suffix(self):
