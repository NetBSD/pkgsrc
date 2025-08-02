$NetBSD: patch-src_pip___internal_req_req__install.py,v 1.3 2025/08/02 17:24:33 adam Exp $

Allow pip install --executable=/path to set path in script #! lines.
https://github.com/pypa/pip/issues/12087
https://github.com/pypa/pip/pull/12088

--- src/pip/_internal/req/req_install.py.orig	2025-07-30 21:31:52.000000000 +0000
+++ src/pip/_internal/req/req_install.py
@@ -813,6 +813,7 @@ class InstallRequirement:
         root: str | None = None,
         home: str | None = None,
         prefix: str | None = None,
+        executable: str | None = None,
         warn_script_location: bool = True,
         use_user_site: bool = False,
         pycompile: bool = True,
@@ -871,6 +872,7 @@ class InstallRequirement:
             self.req.name,
             self.local_file_path,
             scheme=scheme,
+            executable=executable,
             req_description=str(self.req),
             pycompile=pycompile,
             warn_script_location=warn_script_location,
