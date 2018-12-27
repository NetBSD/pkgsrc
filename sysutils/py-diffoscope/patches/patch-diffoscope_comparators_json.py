$NetBSD: patch-diffoscope_comparators_json.py,v 1.1 2018/12/27 15:03:53 joerg Exp $

--- diffoscope/comparators/json.py.orig	2018-12-25 21:53:50.738372750 +0000
+++ diffoscope/comparators/json.py
@@ -39,7 +39,7 @@ class JSONFile(File):
             # Try fuzzy matching for JSON files
             is_text = any(
                 file.magic_file_type.startswith(x)
-                for x in ('ASCII text', 'UTF-8 Unicode text'),
+                for x in ('ASCII text', 'UTF-8 Unicode text')
             )
             if is_text and not file.name.endswith('.json'):
                 buf = f.read(10)
