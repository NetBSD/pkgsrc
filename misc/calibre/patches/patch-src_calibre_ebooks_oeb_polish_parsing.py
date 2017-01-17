$NetBSD: patch-src_calibre_ebooks_oeb_polish_parsing.py,v 1.1 2017/01/17 23:19:24 wiz Exp $

html5lib 0.99999999 moved treebuilders._base to .base to clarify its
status as public, and ihatexml to _ihatexml to clarify as private.

--- src/calibre/ebooks/oeb/polish/parsing.py.orig	2017-01-13 03:38:35.000000000 +0000
+++ src/calibre/ebooks/oeb/polish/parsing.py
@@ -13,8 +13,14 @@ from bisect import bisect
 from lxml.etree import ElementBase, XMLParser, ElementDefaultClassLookup, CommentBase, fromstring, Element as LxmlElement
 
 from html5lib.constants import namespaces, tableInsertModeElements, EOF
-from html5lib.treebuilders._base import TreeBuilder as BaseTreeBuilder
-from html5lib.ihatexml import InfosetFilter, DataLossWarning
+try:
+    from html5lib.treebuilders.base import TreeBuilder as BaseTreeBuilder
+except:
+    from html5lib.treebuilders._base import TreeBuilder as BaseTreeBuilder
+try:
+    from html5lib._ihatexml import InfosetFilter, DataLossWarning
+except:
+    from html5lib.ihatexml import InfosetFilter, DataLossWarning
 from html5lib.html5parser import HTMLParser
 
 from calibre import xml_replace_entities
