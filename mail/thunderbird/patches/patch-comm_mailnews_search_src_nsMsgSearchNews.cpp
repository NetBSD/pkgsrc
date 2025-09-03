$NetBSD: patch-comm_mailnews_search_src_nsMsgSearchNews.cpp,v 1.1 2025/09/03 14:17:01 ryoon Exp $

* Fix runtime segfault when sending EAI email.

--- comm/mailnews/search/src/nsMsgSearchNews.cpp.orig	2025-09-02 06:19:15.010445347 +0000
+++ comm/mailnews/search/src/nsMsgSearchNews.cpp
@@ -61,7 +61,7 @@ char16_t* nsMsgSearchNews::EncodeToWildm
   if (caseInsensitiveValue) {
     char16_t* walkValue = caseInsensitiveValue;
     while (*value) {
-      if (isalpha(*value)) {
+      if (isalpha((unsigned char)(*value))) {
         *walkValue++ = (char16_t)'[';
         *walkValue++ = ToUpperCase((char16_t)*value);
         *walkValue++ = ToLowerCase((char16_t)*value);
