$NetBSD: patch-mozilla_js_src_shell_jsoptparse.cpp,v 1.2 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/js/src/shell/jsoptparse.cpp.orig	2016-04-07 21:33:25.000000000 +0000
+++ mozilla/js/src/shell/jsoptparse.cpp
@@ -95,7 +95,7 @@ PrintParagraph(const char* text, unsigne
         ++it;
 
     while (*it != '\0') {
-        MOZ_ASSERT(!isspace(*it));
+        MOZ_ASSERT(!isspace((unsigned char)*it));
 
         /* Delimit the current token. */
         const char* limit = it;
