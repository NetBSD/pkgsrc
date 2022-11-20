$NetBSD: patch-numpy_distutils_log.py,v 1.1 2022/11/20 19:03:47 adam Exp $

Backport distutils.log.Log from setuptools < 65.6.0.

--- numpy/distutils/log.py.orig	2022-11-20 17:58:45.000000000 +0000
+++ numpy/distutils/log.py
@@ -1,8 +1,8 @@
 # Colored log
 import sys
 from distutils.log import *  # noqa: F403
-from distutils.log import Log as old_Log
 from distutils.log import _global_log
+from logging import Logger
 
 from numpy.distutils.misc_util import (red_text, default_text, cyan_text,
         green_text, is_sequence, is_string)
@@ -16,7 +16,48 @@ def _fix_args(args,flag=1):
     return args
 
 
-class Log(old_Log):
+class Log(Logger):
+    def __init__(self, threshold=WARN):
+        self.threshold = threshold
+
+    def _log(self, level, msg, args):
+        if level not in (DEBUG, INFO, WARN, ERROR, FATAL):
+            raise ValueError('%s wrong log level' % str(level))
+
+        if level >= self.threshold:
+            if args:
+                msg = msg % args
+            if level in (WARN, ERROR, FATAL):
+                stream = sys.stderr
+            else:
+                stream = sys.stdout
+            try:
+                stream.write('%s\n' % msg)
+            except UnicodeEncodeError:
+                # emulate backslashreplace error handler
+                encoding = stream.encoding
+                msg = msg.encode(encoding, "backslashreplace").decode(encoding)
+                stream.write('%s\n' % msg)
+            stream.flush()
+
+    def log(self, level, msg, *args):
+        self._log(level, msg, args)
+
+    def debug(self, msg, *args):
+       self._log(DEBUG, msg, args)
+
+    def info(self, msg, *args):
+        self._log(INFO, msg, args)
+
+    def warn(self, msg, *args):
+        self._log(WARN, msg, args)
+
+    def error(self, msg, *args):
+        self._log(ERROR, msg, args)
+
+    def fatal(self, msg, *args):
+        self._log(FATAL, msg, args)
+
     def _log(self, level, msg, args):
         if level >= self.threshold:
             if args:
@@ -44,6 +85,7 @@ class Log(old_Log):
 
 
 _global_log.__class__ = Log
+_global_log.threshold = WARN
 
 good = _global_log.good
 
