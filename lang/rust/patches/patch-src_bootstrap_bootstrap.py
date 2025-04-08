$NetBSD: patch-src_bootstrap_bootstrap.py,v 1.26 2025/04/08 09:31:07 wiz Exp $

Use `uname -p` on NetBSD, as that is reliable and sensible there.
Handle earmv[67]hf for NetBSD.
Also use @PREFIX@ and not $ORIGIN in rpath.

--- src/bootstrap/bootstrap.py.orig	2025-02-17 18:17:27.000000000 +0000
+++ src/bootstrap/bootstrap.py
@@ -323,6 +323,11 @@ def default_build_triple(verbose):
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
@@ -427,10 +432,16 @@ def default_build_triple(verbose):
             kernel = "linux-androideabi"
         else:
             kernel += "eabihf"
-    elif cputype in {"armv7l", "armv8l"}:
+    elif cputype in {"armv6hf", "earmv6hf"}:
+        cputype = "armv6"
+        if kernel == "unknown-netbsd":
+            kernel += "-eabihf"
+    elif cputype in {"armv7l", "earmv7hf", "armv8l"}:
         cputype = "armv7"
         if kernel == "linux-android":
             kernel = "linux-androideabi"
+        elif kernel == "unknown-netbsd":
+            kernel += "-eabihf"
         else:
             kernel += "eabihf"
     elif cputype == "mips":
@@ -688,11 +699,11 @@ class RustBuild(object):
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
@@ -839,7 +850,10 @@ class RustBuild(object):
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
