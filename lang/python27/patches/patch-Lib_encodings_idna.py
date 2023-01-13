$NetBSD: patch-Lib_encodings_idna.py,v 1.1.2.2 2023/01/13 19:54:39 bsiegert Exp $

Security fix for CVE-2022-45061: CPU denial of service via inefficient IDNA decoder
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/raw/64f3700b7679f9f8a385d99e3862a758b14e1d28/f/00394-cve-2022-45061-cpu-denial-of-service-via-inefficient-idna-decoder.patch

--- Lib/encodings/idna.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/encodings/idna.py
@@ -39,23 +39,21 @@ def nameprep(label):
 
     # Check bidi
     RandAL = map(stringprep.in_table_d1, label)
-    for c in RandAL:
-        if c:
-            # There is a RandAL char in the string. Must perform further
-            # tests:
-            # 1) The characters in section 5.8 MUST be prohibited.
-            # This is table C.8, which was already checked
-            # 2) If a string contains any RandALCat character, the string
-            # MUST NOT contain any LCat character.
-            if filter(stringprep.in_table_d2, label):
-                raise UnicodeError("Violation of BIDI requirement 2")
-
-            # 3) If a string contains any RandALCat character, a
-            # RandALCat character MUST be the first character of the
-            # string, and a RandALCat character MUST be the last
-            # character of the string.
-            if not RandAL[0] or not RandAL[-1]:
-                raise UnicodeError("Violation of BIDI requirement 3")
+    if any(RandAL):
+        # There is a RandAL char in the string. Must perform further
+        # tests:
+        # 1) The characters in section 5.8 MUST be prohibited.
+        # This is table C.8, which was already checked
+        # 2) If a string contains any RandALCat character, the string
+        # MUST NOT contain any LCat character.
+        if any(stringprep.in_table_d2(x) for x in label):
+            raise UnicodeError("Violation of BIDI requirement 2")
+        # 3) If a string contains any RandALCat character, a
+        # RandALCat character MUST be the first character of the
+        # string, and a RandALCat character MUST be the last
+        # character of the string.
+        if not RandAL[0] or not RandAL[-1]:
+            raise UnicodeError("Violation of BIDI requirement 3")
 
     return label
 
