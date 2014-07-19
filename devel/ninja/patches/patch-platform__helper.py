$NetBSD: patch-platform__helper.py,v 1.1 2014/07/19 09:01:23 ryoon Exp $

* Add NetBSD support

--- platform_helper.py.orig	2014-06-27 23:37:05.000000000 +0000
+++ platform_helper.py
@@ -19,7 +19,7 @@ import sys
 
 def platforms():
     return ['linux', 'darwin', 'freebsd', 'openbsd', 'solaris', 'sunos5',
-            'mingw', 'msvc', 'gnukfreebsd', 'bitrig']
+            'mingw', 'msvc', 'gnukfreebsd', 'bitrig', 'netbsd']
 
 class Platform(object):
     def __init__(self, platform):
@@ -43,6 +43,8 @@ class Platform(object):
             self._platform = 'msvc'
         elif self._platform.startswith('bitrig'):
             self._platform = 'bitrig'
+        elif self._platform.startswith('netbsd'):
+            self._platform = 'netbsd'
 
     def platform(self):
         return self._platform
@@ -81,3 +83,6 @@ class Platform(object):
 
     def is_bitrig(self):
         return self._platform == 'bitrig'
+
+    def is_netbsd(self):
+        return self._platform == 'netbsd'
