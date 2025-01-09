$NetBSD: patch-setup.py,v 1.3 2025/01/09 21:05:49 ktnb Exp $

First chunk:
https://github.com/mypaint/mypaint/commit/032a155b72f2b021f66a994050d83f07342d04af

Chunks two & three:
Don't force pure standard mode as it depends on various extensions
anyway. Explicitly set _NETBSD_SOURCE since Python's config.h pollutes
the namespace with it.

Chunk four:
Upstream forgot to update the version here

--- setup.py.orig	2020-05-29 16:40:02.000000000 +0000
+++ setup.py
@@ -632,7 +632,7 @@ class InstallScripts (install_scripts):
         self.announce("installing %s as %s" % (src, targ_basename), level=2)
         if self.dry_run:
             return []
-        with open(src, "rU") as in_fp:
+        with open(src, "r") as in_fp:
             with open(targ, "w") as out_fp:
                 line = in_fp.readline().rstrip()
                 if line.startswith("#!"):
@@ -863,7 +863,7 @@ def get_ext_modules():
     import numpy
 
     extra_compile_args = [
-        '--std=c++11',
+        '--std=gnu++11',
         '-Wall',
         '-Wno-sign-compare',
         '-Wno-write-strings',
@@ -883,6 +883,8 @@ def get_ext_modules():
         # Look up libraries dependencies relative to the library.
         extra_link_args.append('-Wl,-z,origin')
         extra_link_args.append('-Wl,-rpath,$ORIGIN')
+    if sys.platform.startswith("netbsd"):
+        extra_compile_args.append("-D_NETBSD_SOURCE")
 
     initial_deps = ["%s >= 1.6" % LIBMYPAINT]
     remaining_deps = [
@@ -978,7 +980,7 @@ def get_data_files():
 
 setup(
     name='MyPaint',
-    version='2.0.0a0',
+    version='2.0.1a0',
     description='Simple painting program for use with graphics tablets.',
     author='Andrew Chadwick',
     author_email='a.t.chadwick@gmail.com',
