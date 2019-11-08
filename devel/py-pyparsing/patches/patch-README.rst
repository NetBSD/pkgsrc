$NetBSD: patch-README.rst,v 1.1 2019/11/08 09:47:55 wiz Exp $

Remove Unicode space to fix build with python 3.6.
https://github.com/pyparsing/pyparsing/pull/163

--- README.rst.orig	2019-11-03 21:47:38.000000000 +0000
+++ README.rst
@@ -7,7 +7,7 @@ Introduction
 ============
 
 The pyparsing module is an alternative approach to creating and
-executing simple grammars, vs. the traditional lex/yacc approach, or the
+executing simple grammars, vs. the traditional lex/yacc approach, or the
 use of regular expressions. The pyparsing module provides a library of
 classes that client code uses to construct the grammar directly in
 Python code.
