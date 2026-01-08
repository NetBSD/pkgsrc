$NetBSD: patch-sdk_src_node.cpp,v 1.1 2026/01/08 17:52:19 kikadf Exp $

* Fix ctype(3) tolower usage

--- sdk/src/node.cpp.orig	2026-01-03 22:32:23.317953423 +0000
+++ sdk/src/node.cpp
@@ -197,7 +197,7 @@ bool Node::getExtension(std::string& ext
     ext = nodeName.substr(dotPos + 1);
     for (auto& c : ext)
     {
-        c = static_cast<char>(tolower(c));
+        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
     }
     return true;
 }
