$NetBSD: patch-jaraco_path.py,v 1.1 2021/11/21 10:37:02 wiz Exp $

On python>=3.4, this is in functools.

--- jaraco/path.py.orig	2021-02-25 22:38:22.000000000 +0000
+++ jaraco/path.py
@@ -18,7 +18,7 @@ import importlib
 import pathlib
 from typing import Dict, Union
 
-from singledispatch import singledispatch
+from functools import singledispatch
 
 
 log = logging.getLogger(__name__)
