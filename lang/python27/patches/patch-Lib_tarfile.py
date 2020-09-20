$NetBSD: patch-Lib_tarfile.py,v 1.2 2020/09/20 12:10:27 mgorny Exp $

bpo-39017 (CVE-2019-20907): infinite loop in tarfile.py

taken from:
https://gitweb.gentoo.org/fork/cpython.git/commit/?h=gentoo-2.7-vanilla&id=893e6e3aee483d262df70656a68f63f601720fcd

--- Lib/tarfile.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/tarfile.py
@@ -1400,6 +1400,8 @@ class TarInfo(object):
 
             length, keyword = match.groups()
             length = int(length)
+            if length == 0:
+                raise InvalidHeaderError("invalid header")
             value = buf[match.end(2) + 1:match.start(1) + length - 1]
 
             keyword = keyword.decode("utf8")
