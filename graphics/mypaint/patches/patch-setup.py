$NetBSD: patch-setup.py,v 1.2 2024/01/28 08:19:19 wiz Exp $

First chunk:
https://github.com/mypaint/mypaint/commit/032a155b72f2b021f66a994050d83f07342d04af

Chunks two & three:
Don't force pure standard mode as it depends on various extensions
anyway. Explicitly set _NETBSD_SOURCE since Python's config.h pollutes
the namespace with it.

--- setup.py.orig	2024-01-28 08:16:11.582259663 +0000
+++ setup.py
@@ -570,7 +570,7 @@ class InstallScripts (install_scripts):
         self.announce("installing %s as %s" % (src, targ_basename), level=2)
         if self.dry_run:
             return []
-        with open(src, "rU") as in_fp:
+        with open(src, "r") as in_fp:
             with open(targ, "w") as out_fp:
                 line = in_fp.readline().rstrip()
                 if line.startswith("#!"):
@@ -801,7 +801,7 @@ def get_ext_modules():
     import numpy
 
     extra_compile_args = [
-        '--std=c++11',
+        '-std=gnu++11',
         '-Wall',
         '-Wno-sign-compare',
         '-Wno-write-strings',
@@ -821,6 +821,8 @@ def get_ext_modules():
         # Look up libraries dependencies relative to the library.
         extra_link_args.append('-Wl,-z,origin')
         extra_link_args.append('-Wl,-rpath,$ORIGIN')
+    if sys.platform.startswith("netbsd"):
+        extra_compile_args.append("-D_NETBSD_SOURCE")
 
     initial_deps = ["libmypaint >= 1.5"]
     remaining_deps = [
