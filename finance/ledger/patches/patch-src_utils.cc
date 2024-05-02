$NetBSD: patch-src_utils.cc,v 1.1 2024/05/02 13:27:04 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/utils.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/utils.cc
@@ -516,7 +516,7 @@ strings_list split_arguments(const char 
   char in_quoted_string = '\0';
 
   for (const char * p = line; *p; p++) {
-    if (! in_quoted_string && std::isspace(*p)) {
+    if (! in_quoted_string && std::isspace(static_cast<unsigned char>(*p))) {
       if (q != buf) {
         *q = '\0';
         args.push_back(buf);
