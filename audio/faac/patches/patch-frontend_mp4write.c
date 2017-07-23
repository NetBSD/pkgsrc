$NetBSD: patch-frontend_mp4write.c,v 1.1 2017/07/23 16:01:14 adam Exp $

Do not re-define bswap32() and bswap16().

--- frontend/mp4write.c.orig	2017-07-23 15:44:39.000000000 +0000
+++ frontend/mp4write.c
@@ -46,6 +46,8 @@ mp4config_t mp4config = { 0 };
 
 static FILE *g_fout = NULL;
 
+#include "config.h"
+#ifndef HAVE_SYS_ENDIAN_H
 static inline uint32_t bswap32(uint32_t u32)
 {
 #ifndef WORDS_BIGENDIAN
@@ -61,6 +63,7 @@ static inline uint16_t bswap16(uint16_t 
     return __builtin_bswap16(u16);
 #endif
 }
+#endif
 
 static int dataout(const void *data, int size)
 {
