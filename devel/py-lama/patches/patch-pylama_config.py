$NetBSD: patch-pylama_config.py,v 1.1 2018/07/05 11:23:29 adam Exp $

Fix Python 3.7 compatibility.
https://github.com/klen/pylama/pull/120/commits/fb8cab00ab7881c1f5b01e0b541cde7957f65fb5

--- pylama/config.py.orig	2017-09-13 14:15:27.000000000 +0000
+++ pylama/config.py
@@ -128,7 +128,7 @@ PARSER.add_argument(
     "--hook", action="store_true", help="Install Git (Mercurial) hook.")
 
 PARSER.add_argument(
-    "--async", action="store_true",
+    "--async", action="store_true", dest='async_mode',
     help="Enable async mode. Useful for checking a lot of files. "
     "Unsupported with pylint.")
 
@@ -168,6 +168,8 @@ def parse_options(args=None, config=True
     if config:
         cfg = get_config(str(options.options), rootdir=rootdir)
         for opt, val in cfg.default.items():
+            if opt == 'async':
+                opt = 'async_mode'
             LOGGER.info('Find option %s (%s)', opt, val)
             passed_value = getattr(options, opt, _Default())
             if isinstance(passed_value, _Default):
@@ -199,9 +201,9 @@ def parse_options(args=None, config=True
         if isinstance(value, _Default):
             setattr(options, name, process_value(name, value.value))
 
-    if options.async and 'pylint' in options.linters:
+    if options.async_mode and 'pylint' in options.linters:
         LOGGER.warning('Can\'t parse code asynchronously with pylint enabled.')
-        options.async = False
+        options.async_mode = False
 
     return options
 
