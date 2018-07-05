$NetBSD: patch-pylama_main.py,v 1.1 2018/07/05 11:23:29 adam Exp $

Fix Python 3.7 compatibility.
https://github.com/klen/pylama/pull/120/commits/fb8cab00ab7881c1f5b01e0b541cde7957f65fb5

--- pylama/main.py.orig	2016-10-25 17:22:56.000000000 +0000
+++ pylama/main.py
@@ -7,7 +7,7 @@ from os import walk, path as op
 
 from .config import parse_options, CURDIR, setup_logger
 from .core import LOGGER, run
-from .async import check_async
+from .async_mode import check_async
 
 
 def check_path(options, rootdir=None, candidates=None, code=None):
@@ -43,7 +43,7 @@ def check_path(options, rootdir=None, ca
 
         paths.append(path)
 
-    if options.async:
+    if options.async_mode:
         return check_async(paths, options, rootdir)
 
     errors = []
