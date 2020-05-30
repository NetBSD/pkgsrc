$NetBSD: patch-setup.py,v 1.1 2020/05/30 20:46:09 joerg Exp $

Don't force pure standard mode as it depends on various extensions
anyway. Explicitly set _NETBSD_SOURCE since Python's config.h pollutes
the namespace with it.

--- setup.py.orig	2020-02-15 15:05:23.000000000 +0000
+++ setup.py
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
