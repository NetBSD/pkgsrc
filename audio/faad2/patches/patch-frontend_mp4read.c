$NetBSD: patch-frontend_mp4read.c,v 1.2 2019/06/05 06:07:27 nia Exp $

Do not re-define bswap32() and bswap16().

--- frontend/mp4read.c.orig	2017-12-17 11:18:43.000000000 +0000
+++ frontend/mp4read.c
@@ -46,6 +46,8 @@ mp4config_t mp4config = { 0 };
 
 static FILE *g_fin = NULL;
 
+#include "config.h"
+#ifndef HAVE_SYS_ENDIAN_H
 static inline uint32_t bswap32(const uint32_t u32)
 {
 #ifndef WORDS_BIGENDIAN
@@ -71,6 +73,7 @@ static inline uint16_t bswap16(const uin
 	return u16;
 #endif
 }
+#endif
 
 enum {ERR_OK = 0, ERR_FAIL = -1, ERR_UNSUPPORTED = -2};
 
