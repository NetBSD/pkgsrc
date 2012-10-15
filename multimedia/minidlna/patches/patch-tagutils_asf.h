$NetBSD: patch-tagutils_asf.h,v 1.1 2012/10/15 22:48:02 drochner Exp $

--- tagutils/tagutils-asf.h.orig	2012-10-15 19:37:11.000000000 +0000
+++ tagutils/tagutils-asf.h
@@ -23,7 +23,11 @@
 
 #define __PACKED__  __attribute__((packed))
 
+#ifdef __NetBSD__
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 
 typedef struct _GUID {
 	__u32 l;
@@ -35,6 +39,10 @@ typedef struct _GUID {
 	GUID name = { l, { w1, w2 }, { b1, b2, b3, b4, b5, b6, b7, b8 } }
 #define IsEqualGUID(rguid1, rguid2) (!memcmp(rguid1, rguid2, sizeof(GUID)))
 
+#ifdef __NetBSD__
+#define SWAP32(l) htole32(l)
+#define SWAP16(w) htole16(w)
+#else
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define SWAP32(l) (l)
 #define SWAP16(w) (w)
@@ -42,6 +50,7 @@ typedef struct _GUID {
 #define SWAP32(l) ( (((l) >> 24) & 0x000000ff) | (((l) >> 8) & 0x0000ff00) | (((l) << 8) & 0x00ff0000) | (((l) << 24) & 0xff000000) )
 #define SWAP16(w) ( (((w) >> 8) & 0x00ff) | (((w) << 8) & 0xff00) )
 #endif
+#endif /* NetBSD */
 
 DEFINE_GUID(ASF_StreamHeader, SWAP32(0xb7dc0791), SWAP16(0xa9b7), SWAP16(0x11cf),
 	    0x8e, 0xe6, 0x00, 0xc0, 0x0c, 0x20, 0x53, 0x65);
