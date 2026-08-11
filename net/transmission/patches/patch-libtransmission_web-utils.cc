$NetBSD: patch-libtransmission_web-utils.cc,v 1.1 2026/08/11 14:21:47 riastradh Exp $

Fix ctype(3) abuse.
https://gnats.NetBSD.org/60574

--- libtransmission/web-utils.cc.orig	2024-05-29 01:38:35.000000000 +0000
+++ libtransmission/web-utils.cc
@@ -447,7 +447,7 @@ std::string tr_urlPercentDecode(std::str
         }
 
         in.remove_prefix(pos);
-        if (std::size(in) >= 3 && in[0] == '%' && (std::isxdigit(in[1]) != 0) && (std::isxdigit(in[2]) != 0))
+        if (std::size(in) >= 3 && in[0] == '%' && (std::isxdigit(static_cast<unsigned char>(in[1])) != 0) && (std::isxdigit(static_cast<unsigned char>(in[2])) != 0))
         {
             auto hexstr = std::array<char, 3>{ in[1], in[2], '\0' };
             auto const hex = strtoul(std::data(hexstr), nullptr, 16);
