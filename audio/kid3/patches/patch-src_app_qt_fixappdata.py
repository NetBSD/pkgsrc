$NetBSD: patch-src_app_qt_fixappdata.py,v 1.2 2023/02/01 20:13:31 wiz Exp $

Fix
UnicodeDecodeError: 'ascii' codec can't decode byte 0xd9 in position 305: ordinal not in range(128)

https://bugs.kde.org/show_bug.cgi?id=465144

--- src/app/qt/fixappdata.py.orig	2023-01-12 03:56:49.000000000 +0000
+++ src/app/qt/fixappdata.py
@@ -5,7 +5,7 @@ import sys
 
 
 def fix_appdata():
-    for line in fileinput.input():
+    for line in fileinput.input(encoding="utf-8"):
         line = line.replace('kid3.desktop', 'kid3-qt.desktop')
         sys.stdout.write(line)
 
