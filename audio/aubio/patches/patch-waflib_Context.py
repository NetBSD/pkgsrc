$NetBSD: patch-waflib_Context.py,v 1.1 2026/10/11 07:51:10 adam Exp $

Allow building with Python 3.11+.

--- waflib/Context.py.orig	2018-12-23 11:11:54.000000000 +0000
+++ waflib/Context.py
@@ -2,7 +2,7 @@
 # encoding: utf-8
 # WARNING! Do not edit! https://waf.io/book/index.html#_obtaining_the_waf_file
 
-import os,re,imp,sys
+import os,re,sys,types
 from waflib import Utils,Errors,Logs
 import waflib.Node
 HEXVERSION=0x2000e00
@@ -106,7 +106,7 @@ class Context(ctx):
 				cache[node]=True
 				self.pre_recurse(node)
 				try:
-					function_code=node.read('rU',encoding)
+					function_code=node.read('r',encoding)
 					exec(compile(function_code,node.abspath(),'exec'),self.exec_dict)
 				finally:
 					self.post_recurse(node)
@@ -344,9 +344,9 @@ def load_module(path,encoding=None):
 		return cache_modules[path]
 	except KeyError:
 		pass
-	module=imp.new_module(WSCRIPT_FILE)
+	module=types.ModuleType(WSCRIPT_FILE)
 	try:
-		code=Utils.readf(path,m='rU',encoding=encoding)
+		code=Utils.readf(path,m='r',encoding=encoding)
 	except EnvironmentError:
 		raise Errors.WafError('Could not read the file %r'%path)
 	module_dir=os.path.dirname(path)
