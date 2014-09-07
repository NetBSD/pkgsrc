$NetBSD: patch-PIL_IcnsImagePlugin.py,v 1.1 2014/09/07 09:37:46 spz Exp $

Icns DOS fix -- CVE-2014-3589 
from https://github.com/python-pillow/Pillow/commit/205e056f8f9b06ed7b925cf8aa0874bc4aaf8a7d

--- PIL/IcnsImagePlugin.py.orig	2009-11-01 00:44:11.000000000 +0000
+++ PIL/IcnsImagePlugin.py
@@ -115,6 +115,8 @@ class IcnsFile:
         i = HEADERSIZE
         while i < filesize:
             sig, blocksize = nextheader(fobj)
+            if blocksize <= 0:
+                raise SyntaxError('invalid block header')
             i = i + HEADERSIZE
             blocksize = blocksize - HEADERSIZE
             dct[sig] = (i, blocksize)
