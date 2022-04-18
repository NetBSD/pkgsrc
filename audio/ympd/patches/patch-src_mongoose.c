$NetBSD: patch-src_mongoose.c,v 1.1 2022/04/18 18:43:07 nia Exp $

solarisfixes.h does not exist, and doesn't seem to be needed anyway.

--- src/mongoose.c.orig	2016-02-13 21:01:52.000000000 +0000
+++ src/mongoose.c
@@ -2801,9 +2801,6 @@ static int is_big_endian(void) {
 // START OF SHA-1 code
 // Copyright(c) By Steve Reid <steve@edmweb.com>
 #define SHA1HANDSOFF
-#if defined(__sun)
-#include "solarisfixes.h"
-#endif
 
 union char64long16 { unsigned char c[64]; uint32_t l[16]; };
 
