$NetBSD: patch-src_bootstrap_bootstrap.py,v 1.24 2024/11/24 16:13:43 he Exp $

Use `uname -p` on NetBSD, as that is reliable and sensible there.
Handle earmv[67]hf for NetBSD.
Also use @PREFIX@ and not $ORIGIN in rpath.

--- src/bootstrap/bootstrap.py.orig	2023-07-12 03:32:40.000000000 +0000
+++ src/bootstrap/bootstrap.py
@@ -270,6 +270,11 @@ def default_build_triple(verbose):
         'GNU': 'unknown-hurd',
     }
 
+    # For NetBSD, use `uname -p`, as there it is reliable & sensible
+    if kernel == 'NetBSD':
+        cputype = subprocess.check_output(
+            ['uname', '-p']).strip().decode(default_encoding)
+
     # Consider the direct transformation first and then the special cases
     if kernel in kerneltype_mapper:
         kernel = kerneltype_mapper[kernel]
@@ -373,10 +378,16 @@ def default_build_triple(verbose):
             kernel = 'linux-androideabi'
         else:
             kernel += 'eabihf'
-    elif cputype in {'armv7l', 'armv8l'}:
+    elif cputype in {'armv6hf', 'earmv6hf'}:
+        cputype = 'armv6'
+        if kernel == 'unknown-netbsd':
+            kernel += '-eabihf'
+    elif cputype in {'armv7l', 'earmv7hf', 'armv8l'}:
         cputype = 'armv7'
         if kernel == 'linux-android':
             kernel = 'linux-androideabi'
+        elif kernel == 'unknown-netbsd':
+            kernel += '-eabihf'
         else:
             kernel += 'eabihf'
     elif cputype == 'mips':
@@ -734,6 +745,7 @@ class RustBuild(object):
 
         patchelf = "{}/bin/patchelf".format(nix_deps_dir)
         rpath_entries = [
+	    "@PREFIX@/lib",
             os.path.join(os.path.realpath(nix_deps_dir), "lib")
         ]
         patchelf_args = ["--add-rpath", ":".join(rpath_entries)]
