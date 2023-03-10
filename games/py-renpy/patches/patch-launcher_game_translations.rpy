$NetBSD: patch-launcher_game_translations.rpy,v 1.1 2023/03/10 21:14:39 ryoon Exp $

--- launcher/game/translations.rpy.orig	2022-04-12 03:01:04.392319700 +0000
+++ launcher/game/translations.rpy
@@ -50,10 +50,10 @@ init python:
             return strings_json
 
         try:
-            tempdir = os.path.join(config.basedir, "tmp")
+            tempdir = os.path.expanduser("~/.renpy/tmp")
 
             try:
-                os.makedirs(os.path.join(config.basedir, "tmp"))
+                os.makedirs(os.path.expanduser("~/.renpy/tmp"))
             except Exception:
                 pass
 
