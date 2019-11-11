$NetBSD: patch-src_lev_Proxy.cc,v 1.1 2019/11/11 22:03:01 maya Exp $

Fix C++11 compatibility

--- src/lev/Proxy.cc.orig	2014-12-19 21:24:37.000000000 +0000
+++ src/lev/Proxy.cc
@@ -933,7 +933,7 @@ namespace enigma { namespace lev {
                     } else if (haveLocalCopy) {
                         // plain file
                         basic_ifstream<char> ifs(absExtPath.c_str(), ios::binary | ios::in);
-                        if (ifs != NULL)
+                        if (ifs)
                             Readfile(ifs, extCode);
                         else
                             haveLocalCopy = false;
