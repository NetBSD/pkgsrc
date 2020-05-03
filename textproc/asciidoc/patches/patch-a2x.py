$NetBSD: patch-a2x.py,v 1.1 2020/05/03 12:03:51 tnn Exp $

From 665d86fa0003584b6a62da66be56309e59333d79 Mon Sep 17 00:00:00 2001
From: Christopher Kent Hoadley <chris.hoadley@gmail.com>
Date: Wed, 29 Apr 2020 20:12:01 -0500
Subject: [PATCH] Fix a2x option collection from input file with non-ascii
 encoding (#104)

* Fix a2x Option Collection From Input File With Non-ASCII Encoding

--- a2x.py.orig	2020-03-12 00:31:53.000000000 +0000
+++ a2x.py
@@ -364,11 +364,19 @@ def get_source_options(asciidoc_file):
     result = []
     if os.path.isfile(asciidoc_file):
         options = ''
-        with open(asciidoc_file) as f:
+        with open(asciidoc_file, 'rb') as f:
+            line_number = 0
             for line in f:
-                mo = re.search(r'^//\s*a2x:', line)
+                line_number += 1
+                mo = re.search(b'^//\s*a2x:', line)
                 if mo:
-                    options += ' ' + line[mo.end():].strip()
+                    try:
+                        options += ' ' + line[mo.end():].strip().decode('ascii')
+                    except UnicodeDecodeError as e:
+                        warning(
+                            "Could not decode option to %s " % e.encoding +
+                            "on line %s in %s" % (line_number, asciidoc_file)
+                        )
         parse_options()
     return result
 
