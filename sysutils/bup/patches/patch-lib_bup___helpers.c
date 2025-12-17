$NetBSD: patch-lib_bup___helpers.c,v 1.4 2025/12/17 23:46:21 nia Exp $

If OS does not define htonll as a macro, avoid colliding with it.

--- lib/bup/_helpers.c.orig	2025-12-17 14:20:36.236008733 +0000
+++ lib/bup/_helpers.c
@@ -137,7 +137,7 @@ static void *checked_malloc(size_t n, size_t size)
 // This function should technically be macro'd out if it's going to be used
 // more than ocasionally.  As of this writing, it'll actually never be called
 // in real world bup scenarios (because our packs are < MAX_INT bytes).
-static uint64_t htonll(uint64_t value)
+static uint64_t my_htonll(uint64_t value)
 {
     static const int endian_test = 42;
 
@@ -145,6 +145,8 @@ static uint64_t htonll(uint64_t value)
 	return ((uint64_t)htonl(value & 0xFFFFFFFF) << 32) | htonl(value >> 32);
     return value; // already in network byte order MSB-LSB
 }
+
+#define htonll my_htonll
 #endif
 
 #define INTEGRAL_ASSIGNMENT_FITS(dest, src) INT_ADD_OK(src, 0, dest)
