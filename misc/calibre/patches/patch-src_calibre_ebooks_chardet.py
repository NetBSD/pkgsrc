$NetBSD: patch-src_calibre_ebooks_chardet.py,v 1.1 2023/12/24 09:10:16 spz Exp $

cchardet is a speed-optimized version of the chardet module; we don't have
a cchardet module but a chardet one, so use chardet instead.
This patch is needed for conversion of books from plain text to epub to work.

--- ./src/calibre/ebooks/chardet.py.orig	2022-06-17 02:35:27.000000000 +0000
+++ ./src/calibre/ebooks/chardet.py
@@ -103,7 +103,7 @@ _CHARSET_ALIASES = {"macintosh" : "mac-r
 
 
 def detect(bytestring):
-    from cchardet import detect as implementation
+    from chardet import detect as implementation
     ans = implementation(bytestring)
     enc = ans.get('encoding')
     if enc:
