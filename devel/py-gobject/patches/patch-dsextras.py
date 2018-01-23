$NetBSD: patch-dsextras.py,v 1.1 2018/01/23 11:23:13 adam Exp $

Append custom path.

--- dsextras.py.orig	2011-01-26 17:49:56.000000000 +0000
+++ dsextras.py
@@ -18,6 +18,7 @@ from distutils.extension import Extensio
 from distutils.spawn import find_executable
 
 try:
+    sys.path.append("@PYGTKCODEGEN@")
     import codegen.createdefs
     from codegen.override import Overrides
     from codegen.defsparser import DefsParser
