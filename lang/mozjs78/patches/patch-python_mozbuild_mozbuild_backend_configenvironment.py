$NetBSD: patch-python_mozbuild_mozbuild_backend_configenvironment.py,v 1.1 2024/08/16 10:20:40 nia Exp $

These python libraries were moved out of "collections" and their
original locations were deprecated.

--- python/mozbuild/mozbuild/backend/configenvironment.py.orig	2024-08-16 10:01:11.885260679 +0000
+++ python/mozbuild/mozbuild/backend/configenvironment.py
@@ -9,7 +9,8 @@ import six
 import sys
 import json
 
-from collections import Iterable, OrderedDict
+from collections import OrderedDict
+from collections.abc import Iterable
 from types import ModuleType
 
 import mozpack.path as mozpath
