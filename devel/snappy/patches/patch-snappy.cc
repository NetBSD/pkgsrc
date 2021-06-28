$NetBSD: patch-snappy.cc,v 1.3 2021/06/28 18:46:09 wiz Exp $

Build fix for 1.1.9 from
https://github.com/google/snappy/pull/128/commits/0c716d435abe65250100c2caea0e5126ac4e14bd

--- snappy.cc.orig	2021-05-04 22:53:34.000000000 +0000
+++ snappy.cc
@@ -1014,7 +1014,7 @@ void MemMove(ptrdiff_t dst, const void* 
 }
 
 SNAPPY_ATTRIBUTE_ALWAYS_INLINE
-size_t AdvanceToNextTag(const uint8_t** ip_p, size_t* tag) {
+inline size_t AdvanceToNextTag(const uint8_t** ip_p, size_t* tag) {
   const uint8_t*& ip = *ip_p;
   // This section is crucial for the throughput of the decompression loop.
   // The latency of an iteration is fundamentally constrained by the
