$NetBSD: patch-src_roman.py,v 1.2 2012/08/15 17:18:15 drochner Exp $

* replace deprecated operator `<>' with `!='
* use 3.x compatible exception syntax

--- src/roman.py.orig	2009-07-23 16:34:18.000000000 +0000
+++ src/roman.py
@@ -40,9 +40,9 @@ romanNumeralMap = (('M',  1000),
 def toRoman(n):
     """convert integer to Roman numeral"""
     if not (0 < n < 5000):
-        raise OutOfRangeError, "number out of range (must be 1..4999)"
-    if int(n) <> n:
-        raise NotIntegerError, "decimals can not be converted"
+        raise OutOfRangeError("number out of range (must be 1..4999)")
+    if int(n) != n:
+        raise NotIntegerError("decimals can not be converted")
 
     result = ""
     for numeral, integer in romanNumeralMap:
@@ -67,9 +67,9 @@ romanNumeralPattern = re.compile("""
 def fromRoman(s):
     """convert Roman numeral to integer"""
     if not s:
-        raise InvalidRomanNumeralError, 'Input can not be blank'
+        raise InvalidRomanNumeralError('Input can not be blank')
     if not romanNumeralPattern.search(s):
-        raise InvalidRomanNumeralError, 'Invalid Roman numeral: %s' % s
+        raise InvalidRomanNumeralError('Invalid Roman numeral: %s' % s)
 
     result = 0
     index = 0
