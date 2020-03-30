$NetBSD: patch-docs_md2man.py,v 1.1 2020/03/30 08:02:22 schmonz Exp $

Avoid finding older BeautifulSoup.

--- docs/md2man.py.orig	2020-03-04 20:00:34.000000000 +0000
+++ docs/md2man.py
@@ -1,11 +1,7 @@
 from __future__ import print_function
 import sys, os, markdown, re
-try:
-    from BeautifulSoup import BeautifulSoup
-    bsver = 3
-except ModuleNotFoundError:
-    from bs4 import BeautifulSoup
-    bsver = 4
+from bs4 import BeautifulSoup
+bsver = 4
 
 def _split_lines(s):
     return re.findall(r'([^\n]*\n?)', s)
