$NetBSD: patch-kivy_utils.py,v 1.1 2026/10/28 05:09:43 wiz Exp $

Support NetBSD.

--- kivy/utils.py.orig	2026-10-27 17:58:09.545138203 +0000
+++ kivy/utils.py
@@ -448,6 +448,8 @@ def _get_platform():
         return 'linux'
     elif _sys_platform.startswith('freebsd'):
         return 'linux'
+    elif _sys_platform.startswith('netbsd'):
+        return 'netbsd'
     return 'unknown'
 
 
