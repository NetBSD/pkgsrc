$NetBSD: patch-libtransmission_crypto-utils.cc,v 1.1 2026/08/11 14:21:47 riastradh Exp $

Fix ctype(3) abuse.
https://gnats.NetBSD.org/60574

--- libtransmission/crypto-utils.cc.orig	2024-05-29 01:38:35.000000000 +0000
+++ libtransmission/crypto-utils.cc
@@ -179,8 +179,8 @@ constexpr void tr_hex_to_binary(char con
 
     for (size_t i = 0; i < byte_length; ++i)
     {
-        auto const upper_nibble = Hex.find(std::tolower(*input++));
-        auto const lower_nibble = Hex.find(std::tolower(*input++));
+        auto const upper_nibble = Hex.find(std::tolower(static_cast<unsigned char>(*input++)));
+        auto const lower_nibble = Hex.find(std::tolower(static_cast<unsigned char>(*input++)));
         *output++ = (uint8_t)((upper_nibble << 4) | lower_nibble);
     }
 }
