$NetBSD: patch-js_src_jsopcode.cpp,v 1.1 2016/12/15 23:57:33 joerg Exp $

Comparing char * with 0 makes no sense.

--- js/src/jsopcode.cpp.orig	2016-12-10 20:52:30.687253594 +0000
+++ js/src/jsopcode.cpp
@@ -6067,7 +6067,7 @@ ExpressionDecompiler::write(JSString *s)
 bool
 ExpressionDecompiler::quote(JSString *s, uint32_t quote)
 {
-    return QuoteString(&sprinter, s, quote) >= 0;
+    return QuoteString(&sprinter, s, quote) != 0;
 }
 
 JSAtom *
