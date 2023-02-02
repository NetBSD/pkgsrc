$NetBSD: patch-src_third__party_s2_hash.h,v 1.1 2023/02/02 14:40:33 tnn Exp $

Deal with namespace conflict.

--- src/third_party/s2/hash.h.orig	2020-01-08 16:30:41.000000000 +0000
+++ src/third_party/s2/hash.h
@@ -2,10 +2,10 @@
 #define THIRD_PARTY_S2_HASH_H_
 
 #include <unordered_map>
-#define hash_map std::unordered_map
+#define s2_hash_map std::unordered_map
 
 #include <unordered_set>
-#define hash_set std::unordered_set
+#define s2_hash_set std::unordered_set
 
 #define HASH_NAMESPACE_START namespace std {
 #define HASH_NAMESPACE_END }
