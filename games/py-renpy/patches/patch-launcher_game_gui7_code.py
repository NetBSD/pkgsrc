$NetBSD: patch-launcher_game_gui7_code.py,v 1.1 2023/11/23 15:41:21 ryoon Exp $

* Fix project initialization.

--- launcher/game/gui7/code.py.orig	2023-11-23 13:59:29.060992201 +0000
+++ launcher/game/gui7/code.py
@@ -371,7 +371,8 @@ class CodeGenerator(object):
             shutil.copy(src, dst)
 
     def copy_script(self, name):
-        dst = os.path.join(self.p.prefix, name)
+        #dst = os.path.join(self.p.prefix, name)
+        dst = name
 
         if os.path.exists(dst):
             return
