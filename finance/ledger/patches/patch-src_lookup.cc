$NetBSD: patch-src_lookup.cc,v 1.1 2024/05/02 13:27:04 riastradh Exp $

Fix ctype abuse.
https://github.com/ledger/ledger/pull/2341

--- src/lookup.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/lookup.cc
@@ -188,7 +188,13 @@ lookup_probable_account(const string& id
 
 #if 0
 #if !HAVE_BOOST_REGEX_UNICODE
-          if (pos == 0 || (pos > 0 && !std::isalnum(value_key[pos - 1])))
+          // Probably doesn't make sense with value_key as unistring,
+          // but this code is under #if 0 anyway, so if anyone is
+          // tempted to use this by changing value_key to string, let's
+          // avoid leaving a rake to step on.
+          if (pos == 0 ||
+              (pos > 0 &&
+               !std::isalnum(static_cast<unsigned char>(value_key[pos - 1]))))
             addend++;
 #else
           // jww (2010-03-07): Not yet implemented
