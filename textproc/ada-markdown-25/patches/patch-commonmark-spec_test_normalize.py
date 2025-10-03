$NetBSD: patch-commonmark-spec_test_normalize.py,v 1.1 2025/10/03 13:40:04 dkazankov Exp $

Fix syntax warnings

--- commonmark-spec/test/normalize.py.orig	2025-09-16 23:53:08.000000000 +0300
+++ commonmark-spec/test/normalize.py
@@ -18,7 +18,7 @@
 # Normalization code, adapted from
 # https://github.com/karlcow/markdown-testsuite/
 significant_attrs = ["alt", "href", "src", "title"]
-whitespace_re = re.compile('\s+')
+whitespace_re = re.compile(r'\s+')
 class MyHTMLParser(HTMLParser):
     def __init__(self):
         HTMLParser.__init__(self)
@@ -176,7 +176,7 @@
         '\u2200&amp;&gt;&lt;&quot;'
 
     """
-    html_chunk_re = re.compile("(\<!\[CDATA\[.*?\]\]\>|\<[^>]*\>|[^<]+)")
+    html_chunk_re = re.compile(r'(\<!\[CDATA\[.*?\]\]\>|\<[^>]*\>|[^<]+)')
     try:
         parser = MyHTMLParser()
         # We work around HTMLParser's limitations parsing CDATA
