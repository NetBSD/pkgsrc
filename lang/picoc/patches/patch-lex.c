$NetBSD: patch-lex.c,v 1.2 2015/12/29 23:34:53 dholland Exp $

Fix build.

--- lex.c.orig	2013-12-15 18:41:56.000000000 +0000
+++ lex.c
@@ -26,7 +26,7 @@
 #define MAX_CHAR_VALUE 255      /* maximum value which can be represented by a "char" data type */
 
 static union AnyValue LexAnyValue;
-static struct Value LexValue = { TypeVoid, &LexAnyValue, FALSE, FALSE };
+static struct Value LexValue = { &VoidType, &LexAnyValue, FALSE, FALSE };
 
 struct ReservedWord
 {
