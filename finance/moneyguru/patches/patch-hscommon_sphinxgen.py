$NetBSD: patch-hscommon_sphinxgen.py,v 1.1 2014/09/17 22:37:04 wiz Exp $

Fix build with sphinx-1.2.3, from
https://github.com/hsoft/moneyguru/commit/53ee31a909c9e6021573167dd797b6a9cf8873a1

--- hscommon/sphinxgen.py.orig	2014-01-25 19:13:23.000000000 +0000
+++ hscommon/sphinxgen.py
@@ -66,4 +66,7 @@ def gen(basepath, destpath, changelogpat
     # missing dependencies which are in the virtualenv). Here, we do exactly what is done when
     # calling the command from bash.
     cmd = load_entry_point('Sphinx', 'console_scripts', 'sphinx-build')
-    cmd(['sphinx-build', basepath, destpath])
+    try:
+        cmd(['sphinx-build', basepath, destpath])
+    except SystemExit:
+        print("Sphinx called sys.exit(), but we're cancelling it because we don't acutally want to exit")
