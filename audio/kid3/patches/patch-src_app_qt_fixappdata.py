$NetBSD: patch-src_app_qt_fixappdata.py,v 1.3 2023/02/04 10:45:53 wiz Exp $

https://invent.kde.org/multimedia/kid3/-/commit/cdc47207d2807f47222e904e441f95a523724ed1

--- src/app/qt/fixappdata.py.orig	2023-01-12 03:56:49.000000000 +0000
+++ src/app/qt/fixappdata.py
@@ -5,9 +5,9 @@ import sys
 
 
 def fix_appdata():
-    for line in fileinput.input():
-        line = line.replace('kid3.desktop', 'kid3-qt.desktop')
-        sys.stdout.write(line)
+    for line in fileinput.input(mode='rb'):
+        line = line.replace(b'kid3.desktop', b'kid3-qt.desktop')
+        sys.stdout.buffer.write(line)
 
 if __name__ == '__main__':
     fix_appdata()
