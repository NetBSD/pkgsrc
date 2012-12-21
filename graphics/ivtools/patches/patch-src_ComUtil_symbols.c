$NetBSD: patch-src_ComUtil_symbols.c,v 1.1 2012/12/21 02:58:55 dholland Exp $

Silence extensive const warnings.

--- src/ComUtil/symbols.c~	2008-05-07 16:17:26.000000000 +0000
+++ src/ComUtil/symbols.c
@@ -86,7 +86,7 @@ Summary:
 #include <ComUtil/comutil.h>
 */
 
-int symbol_add (char * string)
+int symbol_add (const char * string)
 
 /*!
 Return Value:  >= 0 unique identifier for this symbol, 
@@ -336,7 +336,7 @@ Summary:
 #include <ComUtil/comutil.h>
 */
 
-int symbol_find (char * string)
+int symbol_find (const char * string)
 
 /*!
 Return Value:  >=0 unique identifier for symbol if symbol found,
