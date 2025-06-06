$NetBSD: patch-waflib_Context.py,v 1.3 2025/06/06 23:03:39 wiz Exp $

Fix build with Python 3.11, 3.12.
https://github.com/jackaudio/jack2/issues/898
https://github.com/jackaudio/jack2/commit/250420381b1a6974798939ad7104ab1a4b9a9994#diff-5cdadb9cd9b71f7c6dda6ca75241b1968009f71cd7c046242929974b61cff061L12

--- waflib/Context.py.orig	2025-06-06 23:01:28.513361828 +0000
+++ waflib/Context.py
@@ -6,7 +6,7 @@
 Classes and functions enabling the command system
 """
 
-import os, re, imp, sys
+import os, re, sys, types
 from waflib import Utils, Errors, Logs
 import waflib.Node
 
@@ -660,7 +660,7 @@ def load_module(path, encoding=None):
 	except KeyError:
 		pass
 
-	module = imp.new_module(WSCRIPT_FILE)
+	module = module = types.ModuleType(WSCRIPT_FILE)
 	try:
 		code = Utils.readf(path, m='r', encoding=encoding)
 	except EnvironmentError:
