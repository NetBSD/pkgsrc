$NetBSD: patch-dot__parser.py,v 1.1 2013/07/22 12:16:18 richard Exp $

_noncomma is obsoleted in the latest pyparsing, fix to work with all versions.

--- dot_parser.py.orig	2012-01-02 23:23:26.000000000 +0000
+++ dot_parser.py
@@ -25,7 +25,7 @@ from pyparsing import __version__ as pyp
 from pyparsing import ( nestedExpr, Literal, CaselessLiteral, Word, Upcase, OneOrMore, ZeroOrMore,
     Forward, NotAny, delimitedList, oneOf, Group, Optional, Combine, alphas, nums,
     restOfLine, cStyleComment, nums, alphanums, printables, empty, quotedString,
-    ParseException, ParseResults, CharsNotIn, _noncomma, dblQuotedString, QuotedString, ParserElement )
+    ParseException, ParseResults, CharsNotIn, dblQuotedString, QuotedString, ParserElement )
 
 
 class P_AttrList:
@@ -414,6 +414,7 @@ def graph_definition():
         
         double_quoted_string = QuotedString('"', multiline=True, unquoteResults=False) # dblQuotedString
 
+        _noncomma = "".join( [ c for c in printables if c != "," ] )
         alphastring_ = OneOrMore(CharsNotIn(_noncomma + ' '))
 
         def parse_html(s, loc, toks):
