$NetBSD: patch-lib_meta.py,v 1.1 2020/03/04 13:51:51 wiz Exp $

Fix error with python-3.7:

  File "/scratch/graphics/mypaint/work/mypaint-2.0.0/lib/meta.py", line 411, in _get_release_info_script
    base, formal, ceremonial = _get_versions(gitprefix=gitprefix)
  File "/scratch/graphics/mypaint/work/mypaint-2.0.0/lib/meta.py", line 267, in _get_versions
    exec(relinfo_fp, relinfo)
TypeError: exec() arg 1 must be a string, bytes or code object

--- lib/meta.py.orig	2020-02-15 15:05:22.000000000 +0000
+++ lib/meta.py
@@ -263,8 +263,7 @@ def _get_versions(gitprefix="gitexport")
     if os.path.isfile("release_info"):
         # If release information from release.sh exists, use that
         relinfo = {}
-        with open("release_info", "rb") as relinfo_fp:
-            exec(relinfo_fp, relinfo)
+        exec(open("release_info").read())
         base_version = relinfo.get(
             "MYPAINT_VERSION_BASE",
             base_version,
