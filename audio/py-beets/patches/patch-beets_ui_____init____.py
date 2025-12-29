$NetBSD: patch-beets_ui_____init____.py,v 1.1 2025/12/29 17:54:58 wiz Exp $

Python 3.14 support from Debian
https://github.com/beetbox/beets/issues/6230

--- beets/ui/__init__.py.orig	2025-10-14 22:51:25.515184900 +0000
+++ beets/ui/__init__.py
@@ -712,7 +712,7 @@ def term_width():
         return fallback
 
     try:
-        buf = fcntl.ioctl(0, termios.TIOCGWINSZ, " " * 4)
+        buf = fcntl.ioctl(0, termios.TIOCGWINSZ, b'\x00' * 8)
     except OSError:
         return fallback
     try:
