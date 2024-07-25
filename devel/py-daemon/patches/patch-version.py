$NetBSD: patch-version.py,v 1.1 2024/07/25 12:29:55 wiz Exp $

Setuptools >= 0.70 compatibility.

--- version.py.orig	2024-07-25 12:25:17.449208258 +0000
+++ version.py
@@ -36,7 +36,7 @@ import setuptools.command.build
 import setuptools.command.build_py
 import setuptools.command.egg_info
 import setuptools.dist
-import setuptools.extern.packaging.version
+import packaging.version
 
 
 def ensure_class_bases_begin_with(namespace, class_name, base_class):
@@ -186,7 +186,7 @@ class ChangeLogEntry:
             # A valid non-version value.
             return None
 
-        valid_version = setuptools.extern.packaging.version.Version(value)
+        valid_version = packaging.version.Version(value)
 
     @classmethod
     def validate_maintainer(cls, value):
