$NetBSD: patch-tools_binman_control.py,v 1.1 2026/02/19 09:45:11 wiz Exp $

adapted from
commit 538719cb6a77934d069e0e64f264457a59a9ebfc
Author: Yannic Moog <y.moog@phytec.de>
Date:   Tue Jul 1 07:45:37 2025 +0200

    binman: migrate from pkg_resources to importlib

--- tools/binman/control.py.orig	2021-01-11 18:11:43.000000000 +0000
+++ tools/binman/control.py
@@ -7,8 +7,8 @@ import glob
 
 from collections import OrderedDict
 import glob
+import importlib.resources as importlib_resources
 import os
-import pkg_resources
 import re
 
 import sys
@@ -79,7 +79,7 @@ def _ReadMissingBlobHelp():
             msg = ''
         return tag, msg
 
-    my_data = pkg_resources.resource_string(__name__, 'missing-blob-help')
+    my_data = importlib_resources.files(__package__).joinpath('missing-blob-help').read_bytes()
     re_tag = re.compile('^([-a-z0-9]+):$')
     result = {}
     tag = None
@@ -126,8 +126,9 @@ def GetEntryModules(include_testing=True):
     Returns:
         Set of paths to entry class filenames
     """
-    glob_list = pkg_resources.resource_listdir(__name__, 'etype')
-    glob_list = [fname for fname in glob_list if fname.endswith('.py')]
+    entries = importlib_resources.files(__package__).joinpath('etype')
+    glob_list = [entry.name for entry in entries.iterdir()
+                 if entry.name.endswith('.py') and entry.is_file()]
     return set([os.path.splitext(os.path.basename(item))[0]
                 for item in glob_list
                 if include_testing or '_testing' not in item])
