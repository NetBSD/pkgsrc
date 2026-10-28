$NetBSD: patch-kivy_core_text_____init____.py,v 1.1 2026/10/28 05:09:43 wiz Exp $

Support NetBSD.

--- kivy/core/text/__init__.py.orig	2026-10-27 17:58:45.353122636 +0000
+++ kivy/core/text/__init__.py
@@ -433,6 +433,11 @@ class LabelBase(object):
                 '/usr/share/fonts', '/usr/local/share/fonts',
                 os.path.expanduser('~/.fonts'),
                 os.path.expanduser('~/.local/share/fonts')]
+        elif platform == 'netbsd':
+            fdirs = [
+                '/usr/X11R7/lib/X11/fonts', '@PREFIX@/share/fonts/X11',
+                os.path.expanduser('~/.fonts'),
+                os.path.expanduser('~/.local/share/fonts')]
         elif platform == 'macosx':
             fdirs = ['/Library/Fonts', '/System/Library/Fonts',
                      os.path.expanduser('~/Library/Fonts')]
