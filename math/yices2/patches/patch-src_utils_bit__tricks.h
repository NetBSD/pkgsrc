$NetBSD: patch-src_utils_bit__tricks.h,v 1.1.1.1 2019/08/24 22:09:16 alnsn Exp $

NetBSD has popcount in libc, pull request https://github.com/SRI-CSL/yices2/pull/134

--- src/utils/bit_tricks.h.orig	2018-10-26 21:33:09.000000000 +0000
+++ src/utils/bit_tricks.h
@@ -55,6 +55,11 @@
 #include <stdint.h>
 #include <assert.h>
 
+#ifdef NETBSD
+/* NetBSD has popcount in libc. */
+#include <strings.h>
+#endif
+
 
 #ifdef __GNUC__
 
@@ -101,9 +106,11 @@ static inline uint32_t clz(uint32_t x) {
   return __builtin_clzl(x);
 }
 
+#ifndef NETBSD
 static inline uint32_t popcount32(uint32_t x) {
   return __builtin_popcountl(x);
 }
+#endif
 
 #else
 //#warning "ctz: uint32_t is (unsigned int)"
@@ -118,9 +125,11 @@ static inline uint32_t clz(uint32_t x) {
   return __builtin_clz(x);
 }
 
+#ifndef NETBSD
 static inline uint32_t popcount32(uint32_t x) {
   return __builtin_popcount(x);
 }
+#endif
 
 #endif
 
@@ -141,9 +150,11 @@ static inline uint32_t clz64(uint64_t x)
   return __builtin_clzll(x);
 }
 
+#ifndef NETBSD
 static inline uint32_t popcount64(uint64_t x) {
   return __builtin_popcountll(x);
 }
+#endif
 
 #else
 // #warning "bit_tricks: uint64_t is (unsigned long)
@@ -158,9 +169,11 @@ static inline uint32_t clz64(uint64_t x)
   return __builtin_clzl(x);
 }
 
+#ifndef NETBSD
 static inline uint32_t popcount64(uint64_t x) {
   return __builtin_popcountl(x);
 }
+#endif
 
 #endif // 64bit versions
 
@@ -223,6 +236,7 @@ static inline uint32_t clz64(uint64_t x)
   return i;
 }
 
+#ifndef NETBSD
 static inline uint32_t popcount32(uint32_t x) {
   uint32_t c;
 
@@ -246,6 +260,7 @@ static inline uint32_t popcount64(uint64
 
   return c;
 }
+#endif /* #ifndef NETBSD */
 
 #endif
 
