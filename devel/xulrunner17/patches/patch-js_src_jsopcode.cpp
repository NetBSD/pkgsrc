$NetBSD: patch-js_src_jsopcode.cpp,v 1.1 2016/12/21 13:36:23 joerg Exp $

Don't check pointers for sign.

--- js/src/jsopcode.cpp.orig	2016-12-19 23:21:39.469638330 +0000
+++ js/src/jsopcode.cpp
@@ -6067,7 +6067,7 @@ ExpressionDecompiler::write(JSString *s)
 bool
 ExpressionDecompiler::quote(JSString *s, uint32_t quote)
 {
-    return QuoteString(&sprinter, s, quote) >= 0;
+    return QuoteString(&sprinter, s, quote);
 }
 
 JSAtom *
