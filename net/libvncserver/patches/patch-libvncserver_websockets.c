$NetBSD: patch-libvncserver_websockets.c,v 1.2 2013/02/27 18:24:51 jperkin Exp $

* byte-order handling for !Linux.

--- libvncserver/websockets.c.orig	2012-05-04 14:19:00.000000000 +0000
+++ libvncserver/websockets.c
@@ -31,12 +31,41 @@
 /* errno */
 #include <errno.h>
 
-#include <byteswap.h>
 #include <string.h>
 #include "rfbconfig.h"
 #include "rfbssl.h"
 #include "rfbcrypto.h"
 
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#include <sys/endian.h>
+#define WS_NTOH64(n) be64toh(n)
+#define WS_NTOH32(n) be32toh(n)
+#define WS_NTOH16(n) be16toh(n)
+#define WS_HTON64(n) htobe64(n)
+#define WS_HTON16(n) htobe16(n)
+#elif defined(__OpenBSD__)
+#include <sys/types.h>
+#define WS_NTOH64(n) betoh64(n)
+#define WS_NTOH32(n) betoh32(n)
+#define WS_NTOH16(n) betoh16(n)
+#define WS_HTON64(n) htobe64(n)
+#define WS_HTON16(n) htobe16(n)
+#elif defined(__APPLE__)
+#include <libkern/OSByteOrder.h>
+#define WS_NTOH64(n) OSSwapBigToHostInt64(n)
+#define WS_NTOH32(n) OSSwapBigToHostInt32(n)
+#define WS_NTOH16(n) OSSwapBigToHostInt16(n)
+#define WS_HTON64(n) OSSwapHostToBigInt64(n)
+#define WS_HTON16(n) OSSwapHostToBitInt16(n)
+#elif defined(__sun)
+#include <sys/byteorder.h>
+#define WS_NTOH64(n) ntohll(n)
+#define WS_NTOH32(n) ntohl(n)
+#define WS_NTOH16(n) ntohs(n)
+#define WS_HTON64(n) htonll(n)
+#define WS_HTON16(n) htons(n)
+#else
+#include <byteswap.h>
 #if defined(__BYTE_ORDER) && defined(__BIG_ENDIAN) && __BYTE_ORDER == __BIG_ENDIAN
 #define WS_NTOH64(n) (n)
 #define WS_NTOH32(n) (n)
@@ -50,6 +79,7 @@
 #define WS_HTON64(n) bswap_64(n)
 #define WS_HTON16(n) bswap_16(n)
 #endif
+#endif
 
 #define B64LEN(__x) (((__x + 2) / 3) * 12 / 3)
 #define WSHLENMAX 14  /* 2 + sizeof(uint64_t) + sizeof(uint32_t) */
