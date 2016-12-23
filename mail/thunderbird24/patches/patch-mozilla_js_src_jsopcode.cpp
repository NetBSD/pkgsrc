$NetBSD: patch-mozilla_js_src_jsopcode.cpp,v 1.1 2016/12/23 22:29:59 joerg Exp $

--- mozilla/js/src/jsopcode.cpp.orig	2014-09-24 05:25:05.000000000 +0000
+++ mozilla/js/src/jsopcode.cpp
@@ -1391,7 +1391,7 @@ ExpressionDecompiler::write(JSString *st
 bool
 ExpressionDecompiler::quote(JSString *s, uint32_t quote)
 {
-    return QuoteString(&sprinter, s, quote) >= 0;
+    return QuoteString(&sprinter, s, quote);
 }
 
 JSAtom *
