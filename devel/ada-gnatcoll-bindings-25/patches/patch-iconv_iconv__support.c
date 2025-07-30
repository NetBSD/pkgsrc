$NetBSD: patch-iconv_iconv__support.c,v 1.1 2025/07/30 17:51:00 dkazankov Exp $

Fix build error on NetBSD 9

--- iconv/iconv_support.c.orig	2024-07-11 14:49:55.000000000 +0300
+++ iconv/iconv_support.c
@@ -31,7 +31,7 @@
     size_t *outbytesleft)
 #else
 size_t gnatcoll_iconv
-   (iconv_t cd,  char** inbuf, size_t *inbytesleft, char** outbuf,
+   (iconv_t cd, const char** inbuf, size_t *inbytesleft, char** outbuf,
     size_t *outbytesleft)
 #endif
 {
