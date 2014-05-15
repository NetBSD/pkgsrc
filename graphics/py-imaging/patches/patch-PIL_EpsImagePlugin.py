$NetBSD: patch-PIL_EpsImagePlugin.py,v 1.1 2014/05/15 06:23:06 spz Exp $

patch for CVE-2014-1932 and CVE-2014-1933 taken from
https://github.com/python-imaging/Pillow/commit/4e9f367dfd3f04c8f5d23f7f759ec12782e10ee7

--- PIL/EpsImagePlugin.py.orig	2009-11-01 00:44:11.000000000 +0000
+++ PIL/EpsImagePlugin.py
@@ -44,7 +44,8 @@ def Ghostscript(tile, size, fp):
 
     import tempfile, os
 
-    file = tempfile.mktemp()
+    out_fd, file = tempfile.mkstemp()
+    os.close(out_fd)
 
     # Build ghostscript command
     command = ["gs",
