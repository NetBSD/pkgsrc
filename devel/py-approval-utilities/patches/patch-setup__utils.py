$NetBSD: patch-setup__utils.py,v 1.1 2022/10/19 11:36:40 schmonz Exp $

Find this code's version, now that it's been extracted out of approvaltests.

--- setup_utils.py.orig	2022-10-16 20:31:10.000000000 +0000
+++ setup_utils.py
@@ -11,7 +11,7 @@ def get_parent_directory():
 
 def get_version():
     _version_file_contents = (
-        get_parent_directory() / "approvaltests" / "version.py"
+        get_parent_directory() / "approval_utilities" / "version.py"
     ).read_text()
     matched = re.search(r'"(.*)"', _version_file_contents)
     return matched.group(1) if matched is not None else "UNKNOWN VERSION"
