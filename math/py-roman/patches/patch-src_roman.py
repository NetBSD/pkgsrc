$NetBSD: patch-src_roman.py,v 1.1.1.1 2011/10/05 07:43:12 obache Exp $

* replace deprecated operator `<>' with `!='

--- src/roman.py.orig	2009-07-23 16:34:18.000000000 +0000
+++ src/roman.py
@@ -41,7 +41,7 @@ def toRoman(n):
     """convert integer to Roman numeral"""
     if not (0 < n < 5000):
         raise OutOfRangeError, "number out of range (must be 1..4999)"
-    if int(n) <> n:
+    if int(n) != n:
         raise NotIntegerError, "decimals can not be converted"
 
     result = ""
