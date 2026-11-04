$NetBSD: patch-src_pip___internal_operations_install_wheel.py,v 1.5 2026/11/04 16:49:12 ryoon Exp $

Allow pip install --executable=/path to set path in script #! lines.
https://github.com/pypa/pip/issues/12087
https://github.com/pypa/pip/pull/12088

--- src/pip/_internal/operations/install/wheel.py.orig	2026-11-02 19:29:21.000000000 +0000
+++ src/pip/_internal/operations/install/wheel.py
@@ -441,6 +441,10 @@ class PipScriptMaker(ScriptMaker):
             sys.exit(%(func)s())
 """)
 
+    def __init__(self, executable, *args, **kwargs):
+        super().__init__(None, *args, **kwargs)
+        self.executable = executable
+
     def make(
         self, specification: str, options: dict[str, Any] | None = None
     ) -> list[str]:
@@ -580,6 +584,7 @@ def _install_wheel(  # noqa: C901, PLR09
     wheel_zip: ZipFile,
     wheel_path: str,
     scheme: Scheme,
+    executable: str | None = None,
     pycompile: bool = True,
     warn_script_location: bool = True,
     direct_url: DirectUrl | None = None,
@@ -788,7 +793,7 @@ def _install_wheel(  # noqa: C901, PLR09
         logger.debug(stdout.getvalue())
 
     # Track scripts even if generation fails before returning their paths.
-    maker = PipScriptMaker(None, scheme.scripts, fileop=record.script_fileop)
+    maker = PipScriptMaker(executable, scheme.scripts, fileop=record.script_fileop)
 
     # Embed the target environment's interpreter in console-script launchers
     # rather than the one running pip, so an in-process install into another
@@ -886,6 +891,7 @@ def install_wheel(
     wheel_path: str,
     scheme: Scheme,
     req_description: str,
+    executable: str | None = None,
     pycompile: bool = True,
     warn_script_location: bool = True,
     direct_url: DirectUrl | None = None,
@@ -906,6 +912,7 @@ def install_wheel(
                 wheel_zip=z,
                 wheel_path=wheel_path,
                 scheme=scheme,
+                executable=executable,
                 pycompile=pycompile,
                 warn_script_location=warn_script_location,
                 direct_url=direct_url,
