$NetBSD: patch-src_google_protobuf_stubs_port.h,v 1.2 2021/05/14 20:46:21 wiz Exp $

Fix parentheses.
https://github.com/protocolbuffers/protobuf/pull/8613/commits/88af5d829c133995b88882370b5813600e4d060c

--- src/google/protobuf/stubs/port.h.orig	2021-05-12 23:23:56.000000000 +0000
+++ src/google/protobuf/stubs/port.h
@@ -263,14 +263,14 @@ static inline uint32 bswap_32(uint32 x) 
 
 #ifndef bswap_64
 static inline uint64 bswap_64(uint64 x) {
-  return (((x & uint64_t{0xFFu)) << 56) |
-          ((x & uint64_t{0xFF00u)) << 40) |
-          ((x & uint64_t{0xFF0000u)) << 24) |
-          ((x & uint64_t{0xFF000000u)) << 8) |
-          ((x & uint64_t{0xFF00000000u)) >> 8) |
-          ((x & uint64_t{0xFF0000000000u)) >> 24) |
-          ((x & uint64_t{0xFF000000000000u)) >> 40) |
-          ((x & uint64_t{0xFF00000000000000u)) >> 56));
+  return (((x & uint64_t{0xFFu}) << 56) |
+          ((x & uint64_t{0xFF00u}) << 40) |
+          ((x & uint64_t{0xFF0000u}) << 24) |
+          ((x & uint64_t{0xFF000000u}) << 8) |
+          ((x & uint64_t{0xFF00000000u}) >> 8) |
+          ((x & uint64_t{0xFF0000000000u}) >> 24) |
+          ((x & uint64_t{0xFF000000000000u}) >> 40) |
+          ((x & uint64_t{0xFF00000000000000u}) >> 56));
 }
 #define bswap_64(x) bswap_64(x)
 #endif
