$NetBSD: patch-setuptools___distutils_command_build__scripts.py,v 1.1 2025/04/22 13:00:03 wiz Exp $

Revert:

v76.0.0
Deprecations and Removals

    Synced with pypa/distutils@5589d7527 including a simplified shebang generation when building scripts (#4863). (#4865)

See:

https://github.com/pypa/distutils/pull/332


--- setuptools/_distutils/command/build_scripts.py.orig	2025-04-19 18:23:10.000000000 +0000
+++ setuptools/_distutils/command/build_scripts.py
@@ -5,6 +5,7 @@ Implements the Distutils 'build_scripts'
 import os
 import re
 import tokenize
+from distutils import sysconfig
 from distutils._log import log
 from stat import ST_MODE
 from typing import ClassVar
@@ -105,8 +106,18 @@ class build_scripts(Command):
         if shebang_match:
             log.info("copying and adjusting %s -> %s", script, self.build_dir)
             if not self.dry_run:
+                if not sysconfig.python_build:
+                    executable = self.executable
+                else:
+                    executable = os.path.join(
+                        sysconfig.get_config_var("BINDIR"),
+                        "python{}{}".format(
+                            sysconfig.get_config_var("VERSION"),
+                            sysconfig.get_config_var("EXE"),
+                        ),
+                    )
                 post_interp = shebang_match.group(1) or ''
-                shebang = f"#!python{post_interp}\n"
+                shebang = "#!" + executable + post_interp + "\n"
                 self._validate_shebang(shebang, f.encoding)
                 with open(outfile, "w", encoding=f.encoding) as outf:
                     outf.write(shebang)
