$NetBSD: patch-src_bootstrap_bootstrap.py,v 1.9 2022/01/21 23:20:36 he Exp $

Use `uname -p` on NetBSD, as that is reliable and sensible there.
Always use RUSTFLAGS with -Copt-level=2.
Handle earmv7hf for NetBSD.

--- src/bootstrap/bootstrap.py.orig	2021-11-29 19:27:11.000000000 +0000
+++ src/bootstrap/bootstrap.py
@@ -218,6 +218,11 @@ def default_build_triple(verbose):
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
@@ -271,6 +276,7 @@ def default_build_triple(verbose):
     cputype_mapper = {
         'BePC': 'i686',
         'aarch64': 'aarch64',
+        'aarch64eb': 'aarch64',
         'amd64': 'x86_64',
         'arm64': 'aarch64',
         'i386': 'i686',
@@ -309,10 +315,12 @@ def default_build_triple(verbose):
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
@@ -936,6 +944,7 @@ class RustBuild(object):
 
         # preserve existing RUSTFLAGS
         env.setdefault("RUSTFLAGS", "")
+        env["RUSTFLAGS"] += " -Copt-level=2"
         build_section = "target.{}".format(self.build)
         target_features = []
         if self.get_toml("crt-static", build_section) == "true":
