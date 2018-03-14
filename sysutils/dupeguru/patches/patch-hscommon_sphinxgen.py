$NetBSD: patch-hscommon_sphinxgen.py,v 1.1 2018/03/14 17:11:26 wiz Exp $

Fix build with sphinx-1.7.1.
https://github.com/hsoft/hscommon/commit/17a12618074ccb1e2e66df566c55c621dd8503a7

--- hscommon/sphinxgen.py.orig	2016-08-17 02:02:50.000000000 +0000
+++ hscommon/sphinxgen.py
@@ -9,7 +9,8 @@
 import os.path as op
 import re
 
-from pkg_resources import load_entry_point
+from distutils.version import LooseVersion 
+from pkg_resources import load_entry_point, get_distribution
 
 from .build import read_changelog_file, filereplace
 
@@ -60,14 +61,21 @@ def gen(basepath, destpath, changelogpat
     filereplace(changelogtmpl, changelog_out, changelog='\n'.join(rendered_logs))
     conf_out = op.join(basepath, 'conf.py')
     filereplace(confpath, conf_out, **confrepl)
-    # We used to call sphinx-build with print_and_do(), but the problem was that the virtualenv
-    # of the calling python wasn't correctly considered and caused problems with documentation
-    # relying on autodoc (which tries to import the module to auto-document, but fail because of
-    # missing dependencies which are in the virtualenv). Here, we do exactly what is done when
-    # calling the command from bash.
-    cmd = load_entry_point('Sphinx', 'console_scripts', 'sphinx-build')
-    try:
-        cmd(['sphinx-build', basepath, destpath])
-    except SystemExit:
-        print("Sphinx called sys.exit(), but we're cancelling it because we don't actually want to exit")
-
+    if LooseVersion(get_distribution("sphinx").version) >= LooseVersion("1.7.0"):
+        from sphinx.cmd.build import build_main as sphinx_build
+        # Call the sphinx_build function, which is the same as doing sphinx-build from cli
+        try:
+            sphinx_build([basepath, destpath])
+        except SystemExit:
+            print("Sphinx called sys.exit(), but we're cancelling it because we don't actually want to exit")
+    else:
+        # We used to call sphinx-build with print_and_do(), but the problem was that the virtualenv
+        # of the calling python wasn't correctly considered and caused problems with documentation
+        # relying on autodoc (which tries to import the module to auto-document, but fail because of
+        # missing dependencies which are in the virtualenv). Here, we do exactly what is done when
+        # calling the command from bash.
+        cmd = load_entry_point('Sphinx', 'console_scripts', 'sphinx-build')
+        try:
+            cmd(['sphinx-build', basepath, destpath])
+        except SystemExit:
+            print("Sphinx called sys.exit(), but we're cancelling it because we don't actually want to exit")
