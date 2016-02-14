$NetBSD: patch-js_src_shell_jsoptparse.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- js/src/shell/jsoptparse.cpp.orig	2015-05-04 00:43:27.000000000 +0000
+++ js/src/shell/jsoptparse.cpp
@@ -90,7 +90,7 @@ PrintParagraph(const char* text, unsigne
         printf("%*s", startColno, "");
 
     while (*it != '\0') {
-        MOZ_ASSERT(!isspace(*it));
+        MOZ_ASSERT(!isspace((unsigned char)*it));
 
         /* Delimit the current token. */
         const char* limit = it;
