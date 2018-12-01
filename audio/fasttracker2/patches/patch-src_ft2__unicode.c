$NetBSD: patch-src_ft2__unicode.c,v 1.1 2018/12/01 18:20:09 fox Exp $

1. Added a type cast to iconv(3) calls to match the prototypes defined
in NetBSD's iconv.h.

2. Added a NetBSD specific iconv_open() call to prevent failures due
to mismatches iconv_open() parameters present in GNU iconv(3).

--- src/ft2_unicode.c.orig	2018-07-01 09:13:52.000000000 +0000
+++ src/ft2_unicode.c
@@ -275,7 +275,11 @@ char *cp437ToUtf8(char *src)
     inLen  = srcLen;
     outPtr = outBuf;
 
+#if defined(__NetBSD__)
+    rc = iconv(cd, (const char **)&inPtr, &inLen, &outPtr, &outLen);
+#else
     rc = iconv(cd, &inPtr, &inLen, &outPtr, &outLen);
+#endif
     iconv(cd, NULL, NULL, &outPtr, &outLen); /* flush */
     iconv_close(cd);
 
@@ -307,6 +311,8 @@ char *utf8ToCp437(char *src, uint8_t rem
     */
 #ifdef __APPLE__
     cd = iconv_open("437//TRANSLIT//IGNORE", "UTF-8-MAC");
+#elif defined(__NetBSD__)
+    cd = iconv_open("437", "UTF-8");    
 #else
     cd = iconv_open("437//TRANSLIT//IGNORE", "UTF-8");
 #endif
@@ -323,7 +329,11 @@ char *utf8ToCp437(char *src, uint8_t rem
     inLen  = srcLen;
     outPtr = outBuf;
 
+#if defined(__NetBSD__)
+    rc = iconv(cd, (const char **)&inPtr, &inLen, &outPtr, &outLen);
+#else
     rc = iconv(cd, &inPtr, &inLen, &outPtr, &outLen);
+#endif
     iconv(cd, NULL, NULL, &outPtr, &outLen); /* flush */
     iconv_close(cd);
 
