$NetBSD: patch-waflib_Context.py,v 1.2 2024/08/15 18:05:05 tnn Exp $

Fix build with Python 3.11, 3.12.
https://github.com/jackaudio/jack2/issues/898
https://github.com/jackaudio/jack2/commit/250420381b1a6974798939ad7104ab1a4b9a9994#diff-5cdadb9cd9b71f7c6dda6ca75241b1968009f71cd7c046242929974b61cff061L12

--- waflib/Context.py.orig	2022-04-15 19:14:06.000000000 +0000
+++ waflib/Context.py
@@ -6,10 +6,17 @@
 Classes and functions enabling the command system
 """
 
-import os, re, imp, sys
+import os, re, sys
 from waflib import Utils, Errors, Logs
 import waflib.Node
 
+if sys.hexversion > 0x3040000:
+	import types
+	class imp(object):
+		new_module = lambda x: types.ModuleType(x)
+else:
+	import imp
+
 # the following 3 constants are updated on each new release (do not touch)
 HEXVERSION=0x2000c00
 """Constant updated on new releases"""
@@ -266,7 +273,7 @@ class Context(ctx):
 				cache[node] = True
 				self.pre_recurse(node)
 				try:
-					function_code = node.read('rU', encoding)
+					function_code = node.read('r', encoding)
 					exec(compile(function_code, node.abspath(), 'exec'), self.exec_dict)
 				finally:
 					self.post_recurse(node)
@@ -662,7 +669,7 @@ def load_module(path, encoding=None):
 
 	module = imp.new_module(WSCRIPT_FILE)
 	try:
-		code = Utils.readf(path, m='rU', encoding=encoding)
+		code = Utils.readf(path, m='r', encoding=encoding)
 	except EnvironmentError:
 		raise Errors.WafError('Could not read the file %r' % path)
 
