$NetBSD: patch-mesonbuild_dependencies_base.py,v 1.1 2019/12/11 12:45:29 jperkin Exp $

Backport fix from https://github.com/mesonbuild/meson/pull/6328

--- mesonbuild/dependencies/base.py.orig	2019-10-06 17:01:35.000000000 +0000
+++ mesonbuild/dependencies/base.py
@@ -21,6 +21,7 @@ import re
 import json
 import shlex
 import shutil
+import stat
 import textwrap
 import platform
 import typing
@@ -1840,10 +1841,11 @@ class ExternalProgram:
 
     def _is_executable(self, path):
         suffix = os.path.splitext(path)[-1].lower()[1:]
+        execmask = stat.S_IXUSR | stat.S_IXGRP | stat.S_IXOTH
         if mesonlib.is_windows():
             if suffix in self.windows_exts:
                 return True
-        elif os.access(path, os.X_OK):
+        elif os.stat(path).st_mode & execmask:
             return not os.path.isdir(path)
         return False
 
