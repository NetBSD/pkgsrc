$NetBSD: patch-map8.h,v 1.3 2026/11/04 15:10:53 wiz Exp $

Map8.xs: In function 'XS_Unicode__Map8_recode8':
Map8.xs:358:13: error: implicit declaration of function 'map8_recode8'; did you mean 'map8_recode_8'? [-Wimplicit-function-declaration]
  358 |             map8_recode8(m1, m2, str, res, len, &rlen);
      |             ^~~~~~~~~~~~
      |             map8_recode_8

--- map8.h.orig	2010-01-18 21:08:56.000000000 +0000
+++ map8.h
@@ -80,7 +80,7 @@ U8*   map8_to_str8 (Map8*, U16*, U8*, int, int*);
 
 U16*  map8_to_str16(Map8*, U8*, U16*, int, int*);
 U8*   map8_to_str8 (Map8*, U16*, U8*, int, int*);
-U8*   map8_recode_8(Map8*, Map8*, U8*, U8*, int, int*);
+U8*   map8_recode8(Map8*, Map8*, U8*, U8*, int, STRLEN*);
 
 int   map8_empty_block(Map8*, U8);
 
