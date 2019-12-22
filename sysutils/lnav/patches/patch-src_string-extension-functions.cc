$NetBSD: patch-src_string-extension-functions.cc,v 1.1 2019/12/22 22:30:08 joerg Exp $

--- src/string-extension-functions.cc.orig	2019-12-22 19:53:29.706785775 +0000
+++ src/string-extension-functions.cc
@@ -141,7 +141,7 @@ void regexp_replace(sqlite3_context *ctx
         return;
 
     {
-        string dest(str);
+        pcrecpp::string dest(str);
         reobj->GlobalReplace(repl, &dest);
         sqlite3_result_text(ctx, dest.c_str(), dest.length(), SQLITE_TRANSIENT);
         return;
