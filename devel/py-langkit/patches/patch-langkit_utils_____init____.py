$NetBSD: patch-langkit_utils_____init____.py,v 1.1 2025/10/09 11:25:49 wiz Exp $

Transition uses of the Python pipes module to shlex
"pipes" was removed from Python 3.13.
https://github.com/AdaCore/langkit/commit/dbacb9b5545315e7045ef082dba99d2c96ed1356

--- langkit/utils/__init__.py.orig	2024-09-17 09:18:15.000000000 +0000
+++ langkit/utils/__init__.py
@@ -11,7 +11,6 @@ from contextlib import ExitStack, contex
 from copy import copy
 from enum import Enum
 import os
-import pipes
 import shlex
 import shutil
 from typing import (
@@ -265,7 +264,7 @@ def format_setenv(name: str, path: str) 
     environment variable.
     """
     return (
-        f'{name}={pipes.quote(path)}"{os.pathsep}${name}";'
+        f'{name}={shlex.quote(path)}"{os.pathsep}${name}";'
         f" export {name}"
     )
 
