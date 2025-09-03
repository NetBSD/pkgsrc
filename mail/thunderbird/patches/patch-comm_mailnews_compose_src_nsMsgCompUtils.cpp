$NetBSD: patch-comm_mailnews_compose_src_nsMsgCompUtils.cpp,v 1.1 2025/09/03 14:17:01 ryoon Exp $

* Fix runtime segfault when sending EAI email.

--- comm/mailnews/compose/src/nsMsgCompUtils.cpp.orig	2025-09-02 06:17:25.620880973 +0000
+++ comm/mailnews/compose/src/nsMsgCompUtils.cpp
@@ -159,7 +159,7 @@ static bool isValidHost(const nsCString&
   const auto* cur = host.BeginReading();
   const auto* end = host.EndReading();
   for (; cur < end; ++cur) {
-    if (!isalpha(*cur) && !isdigit(*cur) && *cur != '-' && *cur != '_' &&
+    if (!isalpha((unsigned char)(*cur)) && !isdigit((unsigned char)(*cur)) && *cur != '-' && *cur != '_' &&
         *cur != '.') {
       return false;
     }
