$NetBSD: patch-src_bootstrap_bootstrap.py,v 1.3 2018/11/27 15:45:23 adam Exp $

Use `uname -p` on NetBSD, as that is reliable and sensible there.
Do not use debuginfo; optimize 'bootstrap' instead.
Handle earmv7hf for NetBSD.

--- src/bootstrap/bootstrap.py.orig	2018-11-07 03:22:38.000000000 +0000
+++ src/bootstrap/bootstrap.py
@@ -196,6 +196,11 @@ def default_build_triple():
         'OpenBSD': 'unknown-openbsd'
     }
 
+    # For NetBSD, use `uname -p`, as there it is reliable & sensible
+    if ostype == 'NetBSD':
+        cputype = subprocess.check_output(
+            ['uname', '-p']).strip().decode(default_encoding)
+
     # Consider the direct transformation first and then the special cases
     if ostype in ostype_mapper:
         ostype = ostype_mapper[ostype]
@@ -275,10 +280,12 @@ def default_build_triple():
             ostype = 'linux-androideabi'
         else:
             ostype += 'eabihf'
-    elif cputype in {'armv7l', 'armv8l'}:
+    elif cputype in {'armv7l', 'armv8l', 'earmv7hf'}:
         cputype = 'armv7'
         if ostype == 'linux-android':
             ostype = 'linux-androideabi'
+        elif ostype == 'unknown-netbsd':
+            ostype += '-eabihf'
         else:
             ostype += 'eabihf'
     elif cputype == 'mips':
@@ -622,7 +629,7 @@ class RustBuild(object):
         env["LIBRARY_PATH"] = os.path.join(self.bin_root(), "lib") + \
             (os.pathsep + env["LIBRARY_PATH"]) \
             if "LIBRARY_PATH" in env else ""
-        env["RUSTFLAGS"] = "-Cdebuginfo=2 "
+        env["RUSTFLAGS"] = "-Copt-level=2 "
 
         build_section = "target.{}".format(self.build_triple())
         target_features = []
