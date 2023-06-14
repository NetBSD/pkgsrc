$NetBSD: patch-src_pip___internal_req_req__install.py,v 1.1 2023/06/14 11:30:54 riastradh Exp $

Allow pip install --executable=/path to set path in script #! lines.
https://github.com/pypa/pip/issues/12087
https://github.com/pypa/pip/pull/12088

--- src/pip/_internal/req/req_install.py.orig	2023-04-26 09:23:01.000000000 +0000
+++ src/pip/_internal/req/req_install.py
@@ -766,6 +766,7 @@ class InstallRequirement:
         root: Optional[str] = None,
         home: Optional[str] = None,
         prefix: Optional[str] = None,
+        executable: Optional[str] = None,
         warn_script_location: bool = True,
         use_user_site: bool = False,
         pycompile: bool = True,
@@ -801,6 +802,7 @@ class InstallRequirement:
             self.name,
             self.local_file_path,
             scheme=scheme,
+            executable=executable,
             req_description=str(self.req),
             pycompile=pycompile,
             warn_script_location=warn_script_location,
