$NetBSD: patch-mesonbuild_mesonlib.py,v 1.1 2019/10/04 14:06:19 prlw1 Exp $

Support NetBSD
commit 246b49fe75e8f882f26a0551f89c42ca20ee50c2

--- mesonbuild/mesonlib.py.orig	2019-10-03 21:53:23.886104768 +0000
+++ mesonbuild/mesonlib.py
@@ -460,6 +460,9 @@ def is_debianlike() -> bool:
 def is_dragonflybsd() -> bool:
     return platform.system().lower() == 'dragonfly'
 
+def is_netbsd() -> bool:
+    return platform.system().lower() == 'netbsd'
+
 def is_freebsd() -> bool:
     return platform.system().lower() == 'freebsd'
 
