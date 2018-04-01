$NetBSD: patch-src_util_md5.c,v 1.1 2018/04/01 20:27:21 joerg Exp $

--- src/util/md5.c.orig	2018-03-31 17:41:34.690815147 +0000
+++ src/util/md5.c
@@ -121,8 +121,18 @@ void zzuf_destroy_md5(uint8_t *digest, z
 static void swapwords(uint32_t *buf, unsigned words)
 {
     /* XXX: no need to swap words on little endian machines */
+#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && (__BYTE_ORDER__ - __ORDER_LITTLE_ENDIAN__ + 0 == 0)
+    return;
+#elif defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && (__BYTE_ORDER__ - __ORDER_BIG_ENDIAN__ + 0 == 0)
+    while (words > 0)
+    {
+        uint8_t *b = (uint8_t *)buf;
+        *buf++ = (uint32_t)b[3] << 24 | b[2] << 16 | b[1] << 8 | b[0];
+        words--;
+    }
+#else
 #if defined HAVE_ENDIAN_H
-    if (__BYTE_ORDER == __LITTLE_ENDIAN)
+    if (_BYTE_ORDER == _LITTLE_ENDIAN)
         return;
 #else
     /* This is compile-time optimised with at least -O1 or -Os */
@@ -137,6 +147,7 @@ static void swapwords(uint32_t *buf, uns
         *buf++ = (uint32_t)b[3] << 24 | b[2] << 16 | b[1] << 8 | b[0];
         words--;
     }
+#endif
 }
 
 /* #define F1(x, y, z) (x & y | ~x & z) */
