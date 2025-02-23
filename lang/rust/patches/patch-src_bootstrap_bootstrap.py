$NetBSD: patch-src_bootstrap_bootstrap.py,v 1.25 2025/02/23 08:53:54 he Exp $

Use `uname -p` on NetBSD, as that is reliable and sensible there.
Handle earmv[67]hf for NetBSD.
Also use @PREFIX@ and not $ORIGIN in rpath.

--- src/bootstrap/bootstrap.py.orig	2023-07-12 03:32:40.000000000 +0000
+++ src/bootstrap/bootstrap.py
@@ -286,6 +286,11 @@ def default_build_triple(verbose):
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
@@ -389,10 +394,16 @@ def default_build_triple(verbose):
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
@@ -623,12 +634,12 @@ class RustBuild(object):
                 print('Choosing a pool size of', pool_size, 'for the unpacking of the tarballs')
             p = Pool(pool_size)
             try:
-                # FIXME: A cheap workaround for https://github.com/rust-lang/rust/issues/125578,
-                # remove this once the issue is closed.
-                bootstrap_build_artifacts = os.path.join(self.bootstrap_out(), "debug")
-                if os.path.exists(bootstrap_build_artifacts):
-                    shutil.rmtree(bootstrap_build_artifacts)
-
+#                # FIXME: A cheap workaround for https://github.com/rust-lang/rust/issues/125578,
+#                # remove this once the issue is closed.
+#                bootstrap_build_artifacts = os.path.join(self.bootstrap_out(), "debug")
+#                if os.path.exists(bootstrap_build_artifacts):
+#                    shutil.rmtree(bootstrap_build_artifacts)
+#
                 p.map(unpack_component, tarballs_download_info)
             finally:
                 p.close()
@@ -758,6 +769,7 @@ class RustBuild(object):
 
         patchelf = "{}/bin/patchelf".format(nix_deps_dir)
         rpath_entries = [
+            "@PREFIX@/lib",
             os.path.join(os.path.realpath(nix_deps_dir), "lib")
         ]
         patchelf_args = ["--add-rpath", ":".join(rpath_entries)]
