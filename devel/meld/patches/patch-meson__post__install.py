$NetBSD: patch-meson__post__install.py,v 1.1 2022/12/19 07:09:00 wiz Exp $

Fix bytecode compilation in DESTDIR.
https://gitlab.gnome.org/GNOME/meld/-/commit/469ecdc5d48f1e1ef18d81b24a6717cfe93cc3d6

--- meson_post_install.py.orig	2022-09-04 04:26:14.000000000 +0000
+++ meson_post_install.py
@@ -1,8 +1,9 @@
 #!/usr/bin/env python3
 
+import os
+from os import environ
 import sys
 from compileall import compile_dir
-from os import environ, path
 from subprocess import call
 
 if not environ.get('DESTDIR', ''):
@@ -18,5 +19,11 @@ if not environ.get('DESTDIR', ''):
 # Byte-compilation is enabled by passing the site-packages path to this script
 if len(sys.argv) > 1:
     print('Byte-compiling Python module...')
+    destdir = os.getenv("DESTDIR", "")
     python_source_install_path = sys.argv[1]
-    compile_dir(path.join(python_source_install_path, 'meld'), optimize=1)
+    if destdir:
+        # The install path here will be absolute, so we can't use join()
+        install_path = destdir + os.path.sep + python_source_install_path
+    else:
+        install_path = python_source_install_path
+    compile_dir(os.path.join(install_path, "meld"), optimize=1)
