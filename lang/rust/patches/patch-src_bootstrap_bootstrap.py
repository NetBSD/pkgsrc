$NetBSD: patch-src_bootstrap_bootstrap.py,v 1.1 2018/10/13 10:03:37 he Exp $

Use `uname -p` on NetBSD, as that's reliable & sensible there.
Also force debuginfo to 0, otherwise the build doesn't work on
NetBSD/macppc (powerpc).

--- src/bootstrap/bootstrap.py.orig	2018-09-20 17:28:03.000000000 +0000
+++ src/bootstrap/bootstrap.py
@@ -193,6 +193,11 @@ def default_build_triple():
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
@@ -619,7 +624,7 @@ class RustBuild(object):
         env["LIBRARY_PATH"] = os.path.join(self.bin_root(), "lib") + \
             (os.pathsep + env["LIBRARY_PATH"]) \
             if "LIBRARY_PATH" in env else ""
-        env["RUSTFLAGS"] = "-Cdebuginfo=2 "
+        env["RUSTFLAGS"] = "-Cdebuginfo=0 "
 
         build_section = "target.{}".format(self.build_triple())
         target_features = []
