$NetBSD: patch-doc_pfedoc_docbookdocument.py,v 1.1 2017/12/28 12:46:58 dholland Exp $

Extend existing upstream hack in the docstrings processor to an
apparently similar case of garbled output that's currently breaking
the build.

--- doc/pfedoc/docbookdocument.py~	2009-10-04 13:06:40.000000000 +0000
+++ doc/pfedoc/docbookdocument.py
@@ -4,6 +4,7 @@ from match import Match
 
 def _hack_fixup(text):
     T = text & Match(r"(<function>[^<>]+)\\&lt\\;/link>") >> "\\1</function>"
+    T = T & Match(r"(<literal>[^<>]+)\\&lt\\;/code>") >> "\\1</literal>"
     if T != text:
         pass # print "HACK FIXUP:", text
     return T
