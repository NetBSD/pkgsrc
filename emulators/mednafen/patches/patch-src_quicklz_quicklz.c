$NetBSD: patch-src_quicklz_quicklz.c,v 1.1 2019/04/18 09:12:41 nia Exp $

Use standard inline keyword.

--- src/quicklz/quicklz.c.orig	2019-01-28 06:52:37.000000000 +0000
+++ src/quicklz/quicklz.c
@@ -39,12 +39,12 @@ int qlz_get_setting(int setting)
 	return -1;
 }
 
-__inline unsigned int hash_func(unsigned int i)
+static inline unsigned int hash_func(unsigned int i)
 {
 	return ((i >> 12) ^ i) & 0x0fff;
 }
 
-__inline unsigned int fast_read(void const *src, unsigned int bytes)
+static inline unsigned int fast_read(void const *src, unsigned int bytes)
 {
 #ifndef X86X64
 	unsigned char *p = (unsigned char*)src;
@@ -68,7 +68,7 @@ __inline unsigned int fast_read(void con
 #endif
 }
 
-__inline void fast_write(unsigned int f, void *dst, unsigned int bytes)
+static inline void fast_write(unsigned int f, void *dst, unsigned int bytes)
 {
 #ifndef X86X64
 	unsigned char *p = (unsigned char*)dst;
@@ -118,7 +118,7 @@ __inline void fast_write(unsigned int f,
 #endif
 }
 
-__inline void memcpy_up(unsigned char *dst, const unsigned char *src, unsigned int n)
+static inline void memcpy_up(unsigned char *dst, const unsigned char *src, unsigned int n)
 {
 	// cannot be replaced by overlap handling of memmove() due to LZSS algorithm
 #ifndef X86X64
@@ -151,7 +151,7 @@ __inline void memcpy_up(unsigned char *d
 #endif
 }
 
-__inline unsigned int fast_read_safe(void const *src, unsigned int bytes, const unsigned char *invalid)
+static inline unsigned int fast_read_safe(void const *src, unsigned int bytes, const unsigned char *invalid)
 {
 #ifdef memory_safe 
 	if ((const unsigned char *)src + 4 > (const unsigned char *)invalid)
