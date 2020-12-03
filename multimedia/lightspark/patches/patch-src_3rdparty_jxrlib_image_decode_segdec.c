$NetBSD: patch-src_3rdparty_jxrlib_image_decode_segdec.c,v 1.1 2020/12/03 22:23:33 nia Exp $

Use the more likely to be available bswap64 on non-Linux

--- src/3rdparty/jxrlib/image/decode/segdec.c.orig	2020-07-05 10:31:09.000000000 +0000
+++ src/3rdparty/jxrlib/image/decode/segdec.c
@@ -30,8 +30,13 @@
 #include "decode.h"
 
 #ifndef _WIN32
+#ifdef __linux__
 #include <byteswap.h>
 #define _byteswap_ulong(x) bswap_64(x)
+#else
+#include <sys/endian.h>
+#define _byteswap_ulong(x) bswap64(x)
+#endif
 #endif
 
 #ifdef MEM_TRACE
