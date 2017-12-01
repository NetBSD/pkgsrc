$NetBSD: patch-frontend_mp4read.c,v 1.1 2017/12/01 11:17:51 adam Exp $

Do not re-define bswap32() and bswap16().

--- frontend/mp4read.c.orig	2017-12-01 11:02:01.786551844 +0000
+++ frontend/mp4read.c
@@ -45,6 +45,8 @@ mp4config_t mp4config = { 0 };
 
 static FILE *g_fin = NULL;
 
+#include "config.h"
+#ifndef HAVE_SYS_ENDIAN_H
 static inline uint32_t bswap32(uint32_t u32)
 {
 #ifndef WORDS_BIGENDIAN
@@ -58,6 +60,7 @@ static inline uint16_t bswap16(uint16_t 
     return __builtin_bswap16(u16);
 #endif
 }
+#endif
 
 enum {ERR_OK = 0, ERR_FAIL = -1, ERR_UNSUPPORTED = -2};
 
