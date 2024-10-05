$NetBSD: patch-setup.py,v 1.2 2024/10/05 13:34:19 rhialto Exp $

- Surely this should work in some other way, but without this,
  "setup.py build" errors out with "error: invalid command 'build_mo'".

  It turns out that the created .po files aren't even installed, so
  why bother building them... but if you want to, the code is there,
  commented out.

- Do NOT build any extensions in Rust, especially not if their functionality
  is totally trivial and there is an implementation in Python anyway.
  Also we have set CIBUILDWHEEL=1 in the environment.

  At some point we likely will no longer be able to avoid Rust. In the mean
  time, commented-out fragments in the Makefile remain for the case where
  one wants to try using Rust.

--- setup.py.orig	2024-06-27 14:42:24.000000000 +0000
+++ setup.py
@@ -79,10 +79,16 @@ class build_man(Command):
 
 from setuptools.command.build import build
 
-build.sub_commands.append(("build_mo", lambda _: True))
+#save = sys.path
+#sys.path.append("./breezy")
+#from bzr_distutils import build_mo
+#sys.path = save
+
+# build.sub_commands.append(('build_mo', lambda _: True))
 
 command_classes = {
     "build_man": build_man,
+#    "build_mo": build_mo,
 }
 
 from distutils import log
@@ -220,7 +226,7 @@ import site
 site.ENABLE_USER_SITE = "--user" in sys.argv
 
 rust_extensions = [
-    RustExtension("breezy.bzr._rio_rs", "lib-rio/Cargo.toml", binding=Binding.PyO3),
+    # RustExtension("breezy.bzr._rio_rs", "lib-rio/Cargo.toml", binding=Binding.PyO3),
 ]
 entry_points = {}
 
