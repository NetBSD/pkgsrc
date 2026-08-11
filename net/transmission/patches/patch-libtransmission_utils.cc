$NetBSD: patch-libtransmission_utils.cc,v 1.1 2026/08/11 14:21:47 riastradh Exp $

--- libtransmission/utils.cc.orig	2026-06-29 23:12:56.000000000 +0000
+++ libtransmission/utils.cc
@@ -383,7 +383,7 @@ std::string tr_win32_format_message(uint
     LocalFree(wide_text);
 
     // Most (all?) messages contain "\r\n" in the end, chop it
-    while (!std::empty(text) && isspace(text.back()) != 0)
+    while (!std::empty(text) && isspace(static_cast<unsigned char>(text.back())) != 0)
     {
         text.resize(text.size() - 1);
     }
