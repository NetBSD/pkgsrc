$NetBSD: patch-langkit_compiled__types.py,v 1.2 2025/10/09 15:18:55 dkazankov Exp $

Transition uses of the Python pipes module to shlex
"pipes" was removed from Python 3.13.
https://github.com/AdaCore/langkit/commit/dbacb9b5545315e7045ef082dba99d2c96ed1356

--- langkit/compiled_types.py.orig	2024-12-10 12:23:59.000000000 +0200
+++ langkit/compiled_types.py
@@ -6,7 +6,7 @@
 from dataclasses import dataclass
 import difflib
 from itertools import count, takewhile
-import pipes
+import shlex
 from typing import (
     Any,
     Callable,
