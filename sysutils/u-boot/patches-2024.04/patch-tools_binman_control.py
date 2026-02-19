$NetBSD: patch-tools_binman_control.py,v 1.1 2026/02/19 09:48:14 wiz Exp $

adapted from
commit 538719cb6a77934d069e0e64f264457a59a9ebfc
Author: Yannic Moog <y.moog@phytec.de>
Date:   Tue Jul 1 07:45:37 2025 +0200

    binman: migrate from pkg_resources to importlib

--- tools/binman/control.py.orig	2024-04-02 10:58:58.000000000 +0000
+++ tools/binman/control.py
@@ -8,12 +8,11 @@ try:
 from collections import OrderedDict
 import glob
 try:
-    import importlib.resources
+    import importlib.resources as importlib_resources
 except ImportError:  # pragma: no cover
     # for Python 3.6
     import importlib_resources
 import os
-import pkg_resources
 import re
 
 import sys
@@ -96,7 +95,7 @@ def _ReadMissingBlobHelp():
             msg = ''
         return tag, msg
 
-    my_data = pkg_resources.resource_string(__name__, 'missing-blob-help')
+    my_data = importlib_resources.files(__package__).joinpath('missing-blob-help').read_bytes()
     re_tag = re.compile('^([-a-z0-9]+):$')
     result = {}
     tag = None
@@ -151,8 +150,9 @@ def GetEntryModules(include_testing=True):
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
@@ -735,7 +735,7 @@ def Binman(args):
     global state
 
     if args.full_help:
-        with importlib.resources.path('binman', 'README.rst') as readme:
+        with importlib_resources.path('binman', 'README.rst') as readme:
             tools.print_full_help(str(readme))
         return 0
 
