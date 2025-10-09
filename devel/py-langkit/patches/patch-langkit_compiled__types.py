$NetBSD: patch-langkit_compiled__types.py,v 1.1 2025/10/09 11:25:49 wiz Exp $

Transition uses of the Python pipes module to shlex
"pipes" was removed from Python 3.13.
https://github.com/AdaCore/langkit/commit/dbacb9b5545315e7045ef082dba99d2c96ed1356

--- langkit/compiled_types.py.orig	2024-09-17 09:18:15.000000000 +0000
+++ langkit/compiled_types.py
@@ -6,7 +6,7 @@ from contextlib import AbstractContextMa
 from dataclasses import dataclass
 import difflib
 from itertools import count, takewhile
-import pipes
+import shlex
 from typing import (
     Any, Callable, ClassVar, Dict, Iterator, List, Optional as Opt, Sequence,
     Set, TYPE_CHECKING, Tuple, Union, ValuesView
