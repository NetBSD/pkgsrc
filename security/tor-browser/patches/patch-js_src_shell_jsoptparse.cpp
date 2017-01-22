$NetBSD: patch-js_src_shell_jsoptparse.cpp,v 1.2 2017/01/22 12:27:22 ryoon Exp $

--- js/src/shell/jsoptparse.cpp.orig	2015-06-18 20:55:32.000000000 +0000
+++ js/src/shell/jsoptparse.cpp
@@ -95,7 +95,7 @@ PrintParagraph(const char* text, unsigne
         ++it;
 
     while (*it != '\0') {
-        MOZ_ASSERT(!isspace(*it));
+        MOZ_ASSERT(!isspace((unsigned char)*it));
 
         /* Delimit the current token. */
         const char* limit = it;
