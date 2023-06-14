$NetBSD: patch-src_pip___internal_commands_install.py,v 1.1 2023/06/14 11:30:54 riastradh Exp $

Allow pip install --executable=/path to set path in script #! lines.
https://github.com/pypa/pip/issues/12087
https://github.com/pypa/pip/pull/12088

--- src/pip/_internal/commands/install.py.orig	2023-04-26 09:23:01.000000000 +0000
+++ src/pip/_internal/commands/install.py
@@ -141,6 +141,14 @@ class InstallCommand(RequirementCommand)
                 "environment."
             ),
         )
+        self.cmd_opts.add_option(
+            "--executable",
+            dest="executable_path",
+            default=None,
+            help=(
+                "Path to executable for #! lines in scripts."
+            ),
+        )
 
         self.cmd_opts.add_option(cmdoptions.src())
 
@@ -452,6 +460,7 @@ class InstallCommand(RequirementCommand)
                 root=options.root_path,
                 home=target_temp_dir_path,
                 prefix=options.prefix_path,
+                executable=options.executable_path,
                 warn_script_location=warn_script_location,
                 use_user_site=options.use_user_site,
                 pycompile=options.compile,
