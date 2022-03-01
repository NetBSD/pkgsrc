$NetBSD: patch-src_bootstrap_bootstrap.py,v 1.10 2022/03/01 16:06:39 he Exp $

Use `uname -p` on NetBSD, as that is reliable and sensible there.
Handle earmv7hf for NetBSD.
Default to non-verbose compilation.

--- src/bootstrap/bootstrap.py.orig	2021-02-10 17:36:44.000000000 +0000
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
@@ -980,7 +988,7 @@ class RustBuild(object):
                 self.cargo()))
         args = [self.cargo(), "build", "--manifest-path",
                 os.path.join(self.rust_root, "src/bootstrap/Cargo.toml")]
-        for _ in range(0, self.verbose):
+        for _ in range(1, self.verbose):
             args.append("--verbose")
         if self.use_locked_deps:
             args.append("--locked")
