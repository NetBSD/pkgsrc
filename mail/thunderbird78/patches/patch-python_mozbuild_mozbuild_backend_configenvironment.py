$NetBSD: patch-python_mozbuild_mozbuild_backend_configenvironment.py,v 1.1 2023/02/05 08:32:24 he Exp $

Adjust for python 3.10

--- python/mozbuild/mozbuild/backend/configenvironment.py.orig	2021-07-12 13:35:01.000000000 +0000
+++ python/mozbuild/mozbuild/backend/configenvironment.py
@@ -9,7 +9,8 @@ import six
 import sys
 import json
 
-from collections import Iterable, OrderedDict
+from collections import OrderedDict
+from collections.abc import Iterable
 from types import ModuleType
 
 import mozpack.path as mozpath
