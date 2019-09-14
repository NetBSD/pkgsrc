$NetBSD: patch-frontend_mp4read.c,v 1.3 2019/09/14 13:34:06 nia Exp $

Avoid conflicting with NetBSD libc.

--- frontend/mp4read.c.orig	2019-09-09 10:28:33.000000000 +0000
+++ frontend/mp4read.c
@@ -46,6 +46,7 @@ mp4config_t mp4config = { 0 };
 
 static FILE *g_fin = NULL;
 
+#ifndef __NetBSD__
 static inline uint32_t bswap32(const uint32_t u32)
 {
 #ifndef WORDS_BIGENDIAN
@@ -75,6 +76,7 @@ static inline uint16_t bswap16(const uin
     return u16;
 #endif
 }
+#endif
 
 enum {ERR_OK = 0, ERR_FAIL = -1, ERR_UNSUPPORTED = -2};
 
