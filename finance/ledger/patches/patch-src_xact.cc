$NetBSD: patch-src_xact.cc,v 1.1 2024/05/02 13:27:04 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/xact.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/xact.cc
@@ -116,8 +116,10 @@ value_t xact_base_t::magnitude() const
 namespace {
   inline bool account_ends_with_special_char(const string& name) {
     string::size_type len(name.length());
-    return (std::isdigit(name[len - 1]) || name[len - 1] == ')' ||
-            name[len - 1] == '}' || name[len - 1] == ']');
+    return (std::isdigit(static_cast<unsigned char>(name[len - 1])) ||
+            name[len - 1] == ')' ||
+            name[len - 1] == '}' ||
+            name[len - 1] == ']');
   }
 
   struct add_balancing_post
