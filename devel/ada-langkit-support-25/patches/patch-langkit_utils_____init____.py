$NetBSD: patch-langkit_utils_____init____.py,v 1.1 2025/10/12 10:00:04 dkazankov Exp $

Transition uses of the Python pipes module to shlex
"pipes" was removed from Python 3.13.
https://github.com/AdaCore/langkit/commit/dbacb9b5545315e7045ef082dba99d2c96ed1356

--- langkit/utils/__init__.py.orig	2024-12-10 12:23:59.000000000 +0200
+++ langkit/utils/__init__.py
@@ -11,7 +11,6 @@
 from copy import copy
 from enum import Enum
 import os
-import pipes
 import shlex
 import shutil
 from typing import (
@@ -273,7 +272,7 @@
     environment variable.
     """
     return (
-        f'{name}={pipes.quote(path)}"{os.pathsep}${name}";'
+        f'{name}={shlex.quote(path)}"{os.pathsep}${name}";'
         f" export {name}"
     )
 
