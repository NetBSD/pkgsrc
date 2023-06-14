$NetBSD: patch-src_pip___internal_operations_install_wheel.py,v 1.1 2023/06/14 11:30:54 riastradh Exp $

Allow pip install --executable=/path to set path in script #! lines.
https://github.com/pypa/pip/issues/12087
https://github.com/pypa/pip/pull/12088

--- src/pip/_internal/operations/install/wheel.py.orig	2023-04-26 09:23:01.000000000 +0000
+++ src/pip/_internal/operations/install/wheel.py
@@ -422,6 +422,9 @@ def _raise_for_invalid_entrypoint(specif
 
 
 class PipScriptMaker(ScriptMaker):
+    def __init__(self, executable, *args, **kwargs):
+        super().__init__(*args, **kwargs)
+        self.executable = executable
     def make(
         self, specification: str, options: Optional[Dict[str, Any]] = None
     ) -> List[str]:
@@ -434,6 +437,7 @@ def _install_wheel(
     wheel_zip: ZipFile,
     wheel_path: str,
     scheme: Scheme,
+    executable: Optional[str] = None,
     pycompile: bool = True,
     warn_script_location: bool = True,
     direct_url: Optional[DirectUrl] = None,
@@ -624,7 +628,7 @@ def _install_wheel(
                         record_installed(pyc_record_path, pyc_path)
         logger.debug(stdout.getvalue())
 
-    maker = PipScriptMaker(None, scheme.scripts)
+    maker = PipScriptMaker(executable, None, scheme.scripts)
 
     # Ensure old scripts are overwritten.
     # See https://github.com/pypa/pip/issues/1800
@@ -721,6 +725,7 @@ def install_wheel(
     wheel_path: str,
     scheme: Scheme,
     req_description: str,
+    executable: Optional[str] = None,
     pycompile: bool = True,
     warn_script_location: bool = True,
     direct_url: Optional[DirectUrl] = None,
@@ -733,6 +738,7 @@ def install_wheel(
                 wheel_zip=z,
                 wheel_path=wheel_path,
                 scheme=scheme,
+                executable=executable,
                 pycompile=pycompile,
                 warn_script_location=warn_script_location,
                 direct_url=direct_url,
