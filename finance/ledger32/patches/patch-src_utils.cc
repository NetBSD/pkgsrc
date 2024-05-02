$NetBSD: patch-src_utils.cc,v 1.2 2024/05/02 12:22:13 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

Fix build with newer boost.

--- src/utils.cc.orig	2024-04-21 16:37:21.648652970 +0000
+++ src/utils.cc
@@ -516,7 +516,7 @@ strings_list split_arguments(const char 
   char in_quoted_string = '\0';
 
   for (const char * p = line; *p; p++) {
-    if (! in_quoted_string && std::isspace(*p)) {
+    if (! in_quoted_string && std::isspace(static_cast<unsigned char>(*p))) {
       if (q != buf) {
         *q = '\0';
         args.push_back(buf);
@@ -849,7 +849,7 @@ path resolve_path(const path& pathname)
   path temp = pathname;
   if (temp.string()[0] == '~')
     temp = expand_path(temp);
-  temp.normalize();
+  temp.lexically_normal();
   return temp;
 }
 
