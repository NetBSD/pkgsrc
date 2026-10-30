$NetBSD: patch-sdk_src_utils.cpp,v 1.2 2026/10/30 08:27:11 kikadf Exp $

* Fix ctype(3) tolower usage

--- sdk/src/utils.cpp.orig	2026-10-07 13:39:33.000000000 +0000
+++ sdk/src/utils.cpp
@@ -2442,7 +2442,7 @@ void tolower_string(std::string& str)
     std::transform(str.begin(),
                    str.end(),
                    str.begin(),
-                   [](char c)
+                   [](unsigned char c)
                    {
                        return static_cast<char>(::tolower(c));
                    });
