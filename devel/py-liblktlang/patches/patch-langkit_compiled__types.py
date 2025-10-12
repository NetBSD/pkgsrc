$NetBSD: patch-langkit_compiled__types.py,v 1.1 2025/10/12 13:18:28 dkazankov Exp $

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
@@ -58,7 +58,7 @@
     :param list[str] args: Elements of the special comment.
     :rtype: str
     """
-    return ('--# {}'.format(' '.join(pipes.quote(a) for a in args))
+    return ('--# {}'.format(' '.join(shlex.quote(a) for a in args))
             if get_context().emitter.generate_gdb_hook else '')
 
 
