$NetBSD: patch-ir_adt_bitfiddle.h,v 1.1 2014/11/06 20:46:01 asau Exp $

--- ir/adt/bitfiddle.h.orig	2012-11-16 15:49:24.000000000 +0000
+++ ir/adt/bitfiddle.h
@@ -72,6 +72,7 @@ static inline int add_saturated(int x, i
  * @param x A 32-bit word.
  * @return The number of bits set in x.
  */
+#if !defined(__NetBSD__)
 static inline unsigned popcount(unsigned x)
 {
 #if defined(__GNUC__) && __GNUC__ >= 4
@@ -85,6 +86,7 @@ static inline unsigned popcount(unsigned
 	return x & 0x3f;
 #endif
 }
+#endif
 
 /**
  * Compute the number of leading zeros in a word.
