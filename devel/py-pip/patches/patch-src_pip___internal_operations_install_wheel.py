$NetBSD: patch-src_pip___internal_operations_install_wheel.py,v 1.3 2026/08/08 07:40:20 wiz Exp $

Allow pip install --executable=/path to set path in script #! lines.
https://github.com/pypa/pip/issues/12087
https://github.com/pypa/pip/pull/12088

--- src/pip/_internal/operations/install/wheel.py.orig	2026-08-04 22:28:08.000000000 +0000
+++ src/pip/_internal/operations/install/wheel.py
@@ -425,6 +425,10 @@ class PipScriptMaker(ScriptMaker):
             sys.exit(%(func)s())
 """)
 
+    def __init__(self, executable, *args, **kwargs):
+        super().__init__(*args, **kwargs)
+        self.executable = executable
+
     def make(
         self, specification: str, options: dict[str, Any] | None = None
     ) -> list[str]:
@@ -437,6 +441,7 @@ def _install_wheel(  # noqa: C901, PLR0915 function is
     wheel_zip: ZipFile,
     wheel_path: str,
     scheme: Scheme,
+    executable: str | None = None,
     pycompile: bool = True,
     warn_script_location: bool = True,
     direct_url: DirectUrl | None = None,
@@ -640,7 +645,7 @@ def _install_wheel(  # noqa: C901, PLR0915 function is
                         record_installed(pyc_record_path, pyc_path)
         logger.debug(stdout.getvalue())
 
-    maker = PipScriptMaker(None, scheme.scripts)
+    maker = PipScriptMaker(executable, None, scheme.scripts)
 
     # Embed the target environment's interpreter in console-script launchers
     # rather than the one running pip, so an in-process install into another
@@ -743,6 +748,7 @@ def install_wheel(
     wheel_path: str,
     scheme: Scheme,
     req_description: str,
+    executable: str | None = None,
     pycompile: bool = True,
     warn_script_location: bool = True,
     direct_url: DirectUrl | None = None,
@@ -756,6 +762,7 @@ def install_wheel(
                 wheel_zip=z,
                 wheel_path=wheel_path,
                 scheme=scheme,
+                executable=executable,
                 pycompile=pycompile,
                 warn_script_location=warn_script_location,
                 direct_url=direct_url,
