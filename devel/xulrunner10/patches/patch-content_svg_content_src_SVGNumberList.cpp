$NetBSD: patch-content_svg_content_src_SVGNumberList.cpp,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- content/svg/content/src/SVGNumberList.cpp.orig	2013-08-28 16:16:27.000000000 +0000
+++ content/svg/content/src/SVGNumberList.cpp
@@ -94,7 +94,7 @@ SVGNumberList::SetValueFromString(const 
   while (tokenizer.hasMoreTokens()) {
     CopyUTF16toUTF8(tokenizer.nextToken(), str); // NS_ConvertUTF16toUTF8
     const char *token = str.get();
-    if (token == '\0') {
+    if (token == 0) {
       return NS_ERROR_DOM_SYNTAX_ERR; // nothing between commas
     }
     char *end;
