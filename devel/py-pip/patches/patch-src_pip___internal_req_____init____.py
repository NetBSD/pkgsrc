$NetBSD: patch-src_pip___internal_req_____init____.py,v 1.2 2025/08/02 17:24:33 adam Exp $

Allow pip install --executable=/path to set path in script #! lines.
https://github.com/pypa/pip/issues/12087
https://github.com/pypa/pip/pull/12088

--- src/pip/_internal/req/__init__.py.orig	2025-07-30 21:31:52.000000000 +0000
+++ src/pip/_internal/req/__init__.py
@@ -41,6 +41,7 @@ def install_given_reqs(
     root: str | None,
     home: str | None,
     prefix: str | None,
+    executable: str | None,
     warn_script_location: bool,
     use_user_site: bool,
     pycompile: bool,
@@ -87,6 +88,7 @@ def install_given_reqs(
                     root=root,
                     home=home,
                     prefix=prefix,
+                    executable=executable,
                     warn_script_location=warn_script_location,
                     use_user_site=use_user_site,
                     pycompile=pycompile,
