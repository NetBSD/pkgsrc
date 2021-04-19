$NetBSD: patch-src_bootstrap_bootstrap.py,v 1.5 2021/04/19 17:08:09 he Exp $

Use `uname -p` on NetBSD, as that is reliable and sensible there.
Do not use debuginfo; optimize 'bootstrap' instead.
Handle earmv7hf for NetBSD.

--- src/bootstrap/bootstrap.py.orig	2021-02-10 17:36:44.000000000 +0000
+++ src/bootstrap/bootstrap.py
@@ -228,6 +228,11 @@ def default_build_triple(verbose):
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
@@ -314,10 +319,12 @@ def default_build_triple(verbose):
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
@@ -793,7 +800,7 @@ class RustBuild(object):
             if "LIBRARY_PATH" in env else ""
         # preserve existing RUSTFLAGS
         env.setdefault("RUSTFLAGS", "")
-        env["RUSTFLAGS"] += " -Cdebuginfo=2"
+        env["RUSTFLAGS"] += " -Copt-level=2"
 
         build_section = "target.{}".format(self.build)
         target_features = []
