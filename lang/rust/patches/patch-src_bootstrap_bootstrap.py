$NetBSD: patch-src_bootstrap_bootstrap.py,v 1.28 2026/01/13 20:48:23 wiz Exp $

Use `uname -p` on NetBSD, as that is reliable and sensible there.
Use @PREFIX@ and not $ORIGIN in rpath.

--- src/bootstrap/bootstrap.py.orig	2025-10-28 16:34:16.000000000 +0000
+++ src/bootstrap/bootstrap.py
@@ -330,6 +330,11 @@ def default_build_triple(verbose):
         "GNU": "unknown-hurd",
     }
 
+    # For NetBSD, use `uname -p`, as there it is reliable & sensible
+    if kernel == 'NetBSD':
+        cputype = subprocess.check_output(
+            ['uname', '-p']).strip().decode(default_encoding)
+
     # Consider the direct transformation first and then the special cases
     if kernel in kerneltype_mapper:
         kernel = kerneltype_mapper[kernel]
@@ -706,11 +711,11 @@ class RustBuild(object):
                 )
             p = Pool(pool_size)
             try:
-                # FIXME: A cheap workaround for https://github.com/rust-lang/rust/issues/125578,
-                # remove this once the issue is closed.
-                bootstrap_build_artifacts = os.path.join(self.bootstrap_out(), "debug")
-                if os.path.exists(bootstrap_build_artifacts):
-                    shutil.rmtree(bootstrap_build_artifacts)
+#                # FIXME: A cheap workaround for https://github.com/rust-lang/rust/issues/125578,
+#                # remove this once the issue is closed.
+#                bootstrap_build_artifacts = os.path.join(self.bootstrap_out(), "debug")
+#                if os.path.exists(bootstrap_build_artifacts):
+#                    shutil.rmtree(bootstrap_build_artifacts)
 
                 p.map(unpack_component, tarballs_download_info)
             finally:
@@ -857,7 +862,10 @@ class RustBuild(object):
             self.nix_deps_dir = nix_deps_dir
 
         patchelf = "{}/bin/patchelf".format(nix_deps_dir)
-        rpath_entries = [os.path.join(os.path.realpath(nix_deps_dir), "lib")]
+        rpath_entries = [
+            "@PREFIX@/lib",
+            os.path.join(os.path.realpath(nix_deps_dir), "lib")
+        ]
         patchelf_args = ["--add-rpath", ":".join(rpath_entries)]
         if ".so" not in fname:
             # Finally, set the correct .interp for binaries
