$NetBSD: patch-numpy_distutils_fcompiler_g95.py,v 1.2 2014/02/28 09:43:11 adam Exp $

Band aid to make sure that pic_flags is actually used.

--- numpy/distutils/fcompiler/g95.py.orig	2010-04-18 10:06:17.000000000 +0000
+++ numpy/distutils/fcompiler/g95.py
@@ -19,9 +19,9 @@ class G95FCompiler(FCompiler):
 
     executables = {
         'version_cmd'  : ["<F90>", "--version"],
-        'compiler_f77' : ["g95", "-ffixed-form"],
-        'compiler_fix' : ["g95", "-ffixed-form"],
-        'compiler_f90' : ["g95"],
+        'compiler_f77' : ["g95", "-ffixed-form", "-fpic"],
+        'compiler_fix' : ["g95", "-ffixed-form", "-fpic"],
+        'compiler_f90' : ["g95", "-fpic"],
         'linker_so'    : ["<F90>", "-shared"],
         'archiver'     : ["ar", "-cr"],
         'ranlib'       : ["ranlib"]
