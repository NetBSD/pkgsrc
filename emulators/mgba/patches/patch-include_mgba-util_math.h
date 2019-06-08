$NetBSD: patch-include_mgba-util_math.h,v 1.1 2019/06/08 22:46:03 nia Exp $

NetBSD defines popcount32 in libc.

--- include/mgba-util/math.h.orig	2017-07-16 19:04:50.000000000 +0000
+++ include/mgba-util/math.h
@@ -10,11 +10,15 @@
 
 CXX_GUARD_START
 
+#ifndef __NetBSD__
 static inline uint32_t popcount32(unsigned bits) {
 	bits = bits - ((bits >> 1) & 0x55555555);
 	bits = (bits & 0x33333333) + ((bits >> 2) & 0x33333333);
 	return (((bits + (bits >> 4)) & 0xF0F0F0F) * 0x1010101) >> 24;
 }
+#else
+unsigned int popcount32(uint32_t);
+#endif
 
 static inline unsigned clz32(uint32_t bits) {
 #if defined(__GNUC__) || __clang__
