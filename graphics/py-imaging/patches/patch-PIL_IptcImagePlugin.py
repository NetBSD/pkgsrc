$NetBSD: patch-PIL_IptcImagePlugin.py,v 1.1 2014/05/15 06:23:06 spz Exp $

patch for CVE-2014-1932 and CVE-2014-1933 taken from
https://github.com/python-imaging/Pillow/commit/4e9f367dfd3f04c8f5d23f7f759ec12782e10ee7

--- PIL/IptcImagePlugin.py.orig	2009-11-01 00:44:12.000000000 +0000
+++ PIL/IptcImagePlugin.py
@@ -173,8 +173,8 @@ class IptcImageFile(ImageFile.ImageFile)
         self.fp.seek(offset)
 
         # Copy image data to temporary file
-        outfile = tempfile.mktemp()
-        o = open(outfile, "wb")
+        o_fd, outfile = tempfile.mkstemp(text=False)
+        o = os.fdopen(o_fd)
         if encoding == "raw":
             # To simplify access to the extracted file,
             # prepend a PPM header
