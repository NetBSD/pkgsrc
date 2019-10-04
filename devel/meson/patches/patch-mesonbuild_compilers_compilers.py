$NetBSD: patch-mesonbuild_compilers_compilers.py,v 1.1 2019/10/04 14:06:19 prlw1 Exp $

Support SunOS-specific GCC behaviour.
Limit GNU ld options correctly.

--- mesonbuild/compilers/compilers.py.orig	2019-06-16 18:54:18.000000000 +0000
+++ mesonbuild/compilers/compilers.py
@@ -198,6 +198,14 @@ apple_buildtype_linker_args = {'plain': 
                                'custom': [],
                                }
 
+sunos_buildtype_linker_args = {'plain': [],
+                               'debug': [],
+                               'debugoptimized': [],
+                               'release': [],
+                               'minsize': [],
+                               'custom': [],
+                               }
+
 gnulike_buildtype_linker_args = {'plain': [],
                                  'debug': [],
                                  'debugoptimized': [],
@@ -1304,7 +1312,7 @@ class Compiler:
         if mesonlib.is_sunos():
             return args
 
-        if get_compiler_is_linuxlike(self):
+        if get_compiler_uses_gnuld(self):
             # Rpaths to use while linking must be absolute. These are not
             # written to the binary. Needed only with GNU ld:
             # https://sourceware.org/bugzilla/show_bug.cgi?id=16936
@@ -1395,6 +1403,7 @@ class CompilerType(enum.Enum):
     GCC_OSX = 1
     GCC_MINGW = 2
     GCC_CYGWIN = 3
+    GCC_SUNOS = 4
 
     CLANG_STANDARD = 10
     CLANG_OSX = 11
@@ -1422,6 +1431,10 @@ class CompilerType(enum.Enum):
         return self.name in ('GCC_OSX', 'CLANG_OSX', 'ICC_OSX', 'PGI_OSX')
 
     @property
+    def is_sunos_compiler(self):
+        return self.name in ('GCC_SUNOS')
+
+    @property
     def is_windows_compiler(self):
         return self.name in ('GCC_MINGW', 'GCC_CYGWIN', 'CLANG_MINGW', 'ICC_WIN', 'ARM_WIN', 'CCRX_WIN', 'PGI_WIN')
 
@@ -1434,7 +1447,7 @@ def get_macos_dylib_install_name(prefix,
     return '@rpath/' + install_name
 
 def get_gcc_soname_args(compiler_type, prefix, shlib_name, suffix, soversion, darwin_versions, is_shared_module):
-    if compiler_type.is_standard_compiler:
+    if compiler_type.is_standard_compiler or compiler_type.is_sunos_compiler:
         sostr = '' if soversion is None else '.' + soversion
         return ['-Wl,-soname,%s%s.%s%s' % (prefix, shlib_name, suffix, sostr)]
     elif compiler_type.is_windows_compiler:
@@ -1912,6 +1925,8 @@ class GnuLikeCompiler(abc.ABC):
     def get_buildtype_linker_args(self, buildtype):
         if self.compiler_type.is_osx_compiler:
             return apple_buildtype_linker_args[buildtype]
+        elif self.compiler_type.is_sunos_compiler:
+            return sunos_buildtype_linker_args[buildtype]
         return gnulike_buildtype_linker_args[buildtype]
 
     @abc.abstractmethod
@@ -1976,6 +1991,8 @@ class GnuLikeCompiler(abc.ABC):
         if self.compiler_type.is_osx_compiler:
             # Apple ld
             return ['-Wl,-undefined,dynamic_lookup']
+        elif self.compiler_type.is_sunos_compiler:
+            return []
         elif self.compiler_type.is_windows_compiler:
             # For PE/COFF this is impossible
             return []
