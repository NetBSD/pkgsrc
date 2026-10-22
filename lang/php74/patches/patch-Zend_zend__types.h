$NetBSD: patch-Zend_zend__types.h,v 1.1 2026/10/22 02:06:45 taca Exp $

Fix for CVE-2026-109618-109619.

--- Zend/zend_types.h.orig	2022-10-31 10:36:14.000000000 +0000
+++ Zend/zend_types.h
@@ -330,6 +330,9 @@ struct _zend_array {
 # define HT_HASH_RESET(ht) do { \
 		char *p = (char*)&HT_HASH(ht, (ht)->nTableMask); \
 		size_t size = HT_HASH_SIZE((ht)->nTableMask); \
+		if (UNEXPECTED(size < 64)) { \
+			memset(p, HT_INVALID_IDX, size); \
+		} else { \
 		__m128i xmm0 = _mm_setzero_si128(); \
 		xmm0 = _mm_cmpeq_epi8(xmm0, xmm0); \
 		ZEND_ASSERT(size >= 64 && ((size & 0x3f) == 0)); \
@@ -341,6 +344,7 @@ struct _zend_array {
 			p += 64; \
 			size -= 64; \
 		} while (size != 0); \
+		} \
 	} while (0)
 #else
 # define HT_HASH_RESET(ht) \
