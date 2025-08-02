$NetBSD: patch-src_pip___internal_operations_install_wheel.py,v 1.2 2025/08/02 17:24:33 adam Exp $

Allow pip install --executable=/path to set path in script #! lines.
https://github.com/pypa/pip/issues/12087
https://github.com/pypa/pip/pull/12088

--- src/pip/_internal/operations/install/wheel.py.orig	2025-07-30 21:31:52.000000000 +0000
+++ src/pip/_internal/operations/install/wheel.py
@@ -417,6 +417,10 @@ class PipScriptMaker(ScriptMaker):
 """
     )
 
+    def __init__(self, executable, *args, **kwargs):
+        super().__init__(*args, **kwargs)
+        self.executable = executable
+
     def make(
         self, specification: str, options: dict[str, Any] | None = None
     ) -> list[str]:
@@ -429,6 +433,7 @@ def _install_wheel(  # noqa: C901, PLR09
     wheel_zip: ZipFile,
     wheel_path: str,
     scheme: Scheme,
+    executable: str | None = None,
     pycompile: bool = True,
     warn_script_location: bool = True,
     direct_url: DirectUrl | None = None,
@@ -630,7 +635,7 @@ def _install_wheel(  # noqa: C901, PLR09
                         record_installed(pyc_record_path, pyc_path)
         logger.debug(stdout.getvalue())
 
-    maker = PipScriptMaker(None, scheme.scripts)
+    maker = PipScriptMaker(executable, None, scheme.scripts)
 
     # Ensure old scripts are overwritten.
     # See https://github.com/pypa/pip/issues/1800
@@ -727,6 +732,7 @@ def install_wheel(
     wheel_path: str,
     scheme: Scheme,
     req_description: str,
+    executable: str | None = None,
     pycompile: bool = True,
     warn_script_location: bool = True,
     direct_url: DirectUrl | None = None,
@@ -739,6 +745,7 @@ def install_wheel(
                 wheel_zip=z,
                 wheel_path=wheel_path,
                 scheme=scheme,
+                executable=executable,
                 pycompile=pycompile,
                 warn_script_location=warn_script_location,
                 direct_url=direct_url,
