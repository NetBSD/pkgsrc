$NetBSD: patch-src_pip___internal_req_____init____.py,v 1.1 2023/06/14 11:30:54 riastradh Exp $

Allow pip install --executable=/path to set path in script #! lines.
https://github.com/pypa/pip/issues/12087
https://github.com/pypa/pip/pull/12088

--- src/pip/_internal/req/__init__.py.orig	2023-04-26 09:23:01.000000000 +0000
+++ src/pip/_internal/req/__init__.py
@@ -40,6 +40,7 @@ def install_given_reqs(
     root: Optional[str],
     home: Optional[str],
     prefix: Optional[str],
+    executable: Optional[str],
     warn_script_location: bool,
     use_user_site: bool,
     pycompile: bool,
@@ -74,6 +75,7 @@ def install_given_reqs(
                     root=root,
                     home=home,
                     prefix=prefix,
+                    executable=executable,
                     warn_script_location=warn_script_location,
                     use_user_site=use_user_site,
                     pycompile=pycompile,
