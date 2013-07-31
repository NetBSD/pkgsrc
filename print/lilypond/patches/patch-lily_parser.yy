$NetBSD: patch-lily_parser.yy,v 1.1 2013/07/31 14:11:57 wiz Exp $

Fix for bison-3.0.

--- lily/parser.yy.orig	2013-01-04 13:41:57.000000000 +0000
+++ lily/parser.yy
@@ -100,7 +100,7 @@ or
 
 
 
-%pure_parser
+%pure-parser
 %locations
 
 
