$NetBSD: patch-src_lookup3_lookup3.c,v 1.2 2016/06/21 18:00:02 joerg Exp $

Use pkgsrc's endian detection.

--- src/lookup3/lookup3.c.orig	2014-07-29 06:26:59.000000000 +0000
+++ src/lookup3/lookup3.c
@@ -38,6 +38,7 @@ on 1 byte), but shoehorning those bytes 
 #include <stdio.h>      /* defines printf for tests */
 #include <time.h>       /* defines time_t for timings in the test */
 
+#if !defined(HASH_LITTLE_ENDIAN) && !defined(HASH_BIG_ENDIAN)
 #ifdef WIN32
 typedef unsigned char uint8_t;
 typedef unsigned short uint16_t;
@@ -71,6 +72,7 @@ typedef unsigned int uint32_t;
 # define HASH_LITTLE_ENDIAN 0
 # define HASH_BIG_ENDIAN 0
 #endif
+#endif
 
 #define hashsize(n) ((uint32_t)1<<(n))
 #define hashmask(n) (hashsize(n)-1)
