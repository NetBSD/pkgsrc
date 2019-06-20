$NetBSD: patch-src_ft2__unicode.c,v 1.3 2019/06/20 11:39:06 fox Exp $

1. Added a type cast to iconv(3) calls to match the prototypes defined
in NetBSD's iconv.h.

2. Added a NetBSD specific iconv_open() call to prevent failures due
to mismatches iconv_open() parameters present in GNU iconv(3).

--- src/ft2_unicode.c.orig	2019-06-18 19:45:46.000000000 +0000
+++ src/ft2_unicode.c
@@ -271,7 +271,11 @@ char *cp437ToUtf8(char *src)
 	inLen = srcLen;
 	outPtr = outBuf;
 
+#if defined(__NetBSD__)
+	rc = iconv(cd, (const char **)&inPtr, &inLen, &outPtr, &outLen);
+#else
 	rc = iconv(cd, &inPtr, &inLen, &outPtr, &outLen);
+#endif
 	iconv(cd, NULL, NULL, &outPtr, &outLen); // flush
 	iconv_close(cd);
 
@@ -301,6 +305,8 @@ char *utf8ToCp437(char *src, bool remove
 
 #ifdef __APPLE__
 	cd = iconv_open("437//TRANSLIT//IGNORE", "UTF-8-MAC");
+#elif defined(__NetBSD__)
+	cd = iconv_open("437", "UTF-8");
 #else
 	cd = iconv_open("437//TRANSLIT//IGNORE", "UTF-8");
 #endif
@@ -317,7 +323,11 @@ char *utf8ToCp437(char *src, bool remove
 	inLen = srcLen;
 	outPtr = outBuf;
 
+#if defined(__NetBSD__)
+	rc = iconv(cd, (const char **)&inPtr, &inLen, &outPtr, &outLen);
+#else
 	rc = iconv(cd, &inPtr, &inLen, &outPtr, &outLen);
+#endif
 	iconv(cd, NULL, NULL, &outPtr, &outLen); // flush
 	iconv_close(cd);
 
