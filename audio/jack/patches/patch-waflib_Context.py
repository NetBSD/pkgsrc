$NetBSD: patch-waflib_Context.py,v 1.1 2022/12/16 07:36:41 wiz Exp $

Fix build with Python 3.11.
https://github.com/jackaudio/jack2/issues/898

--- waflib/Context.py.orig	2021-07-15 06:18:26.000000000 +0000
+++ waflib/Context.py
@@ -266,7 +266,7 @@ class Context(ctx):
 				cache[node] = True
 				self.pre_recurse(node)
 				try:
-					function_code = node.read('rU', encoding)
+					function_code = node.read('r', encoding)
 					exec(compile(function_code, node.abspath(), 'exec'), self.exec_dict)
 				finally:
 					self.post_recurse(node)
@@ -662,7 +662,7 @@ def load_module(path, encoding=None):
 
 	module = imp.new_module(WSCRIPT_FILE)
 	try:
-		code = Utils.readf(path, m='rU', encoding=encoding)
+		code = Utils.readf(path, m='r', encoding=encoding)
 	except EnvironmentError:
 		raise Errors.WafError('Could not read the file %r' % path)
 
