$NetBSD: patch-pytest__flake8.py,v 1.1 2026/11/11 16:08:38 wiz Exp $

pytest 9.1.0 compatibility from
https://github.com/OpenIndiana/oi-userland/pull/19860/changes

--- pytest_flake8.py.orig	2026-11-11 16:03:58.215003395 +0000
+++ pytest_flake8.py
@@ -4,6 +4,7 @@ from io import BytesIO, TextIOWrapper
 import re
 from contextlib import redirect_stdout, redirect_stderr
 from io import BytesIO, TextIOWrapper
+from fnmatch import fnmatch
 
 from flake8.main import application
 
@@ -59,11 +60,11 @@ def pytest_configure(config):
             config._flake8mtimes = config.cache.get(HISTKEY, {})
 
 
-def pytest_collect_file(file_path, path, parent):
+def pytest_collect_file(file_path, parent):
     """Filter files down to which ones should be checked."""
     config = parent.config
     if config.option.flake8 and file_path.suffix in config._flake8exts:
-        flake8ignore = config._flake8ignore(path)
+        flake8ignore = config._flake8ignore(file_path)
         if flake8ignore is not None:
             item = Flake8File.from_parent(
                 parent,
@@ -203,7 +204,12 @@ class Ignorer:
     def __call__(self, path):
         l = []  # noqa: E741
         for glob, ignlist in self.ignores:
-            if not glob or path.fnmatch(glob):
+            mpath = path
+            if glob and '/' in glob:
+                glob = "*" + glob
+            else:
+                mpath = str(path).split("/")[-1]
+            if not glob or fnmatch(mpath, glob):
                 if ignlist is None:
                     return None
                 l.extend(ignlist)
