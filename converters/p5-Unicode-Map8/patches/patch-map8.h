$NetBSD: patch-map8.h,v 1.1 2026/11/04 06:29:04 wiz Exp $

Map8.xs: In function 'XS_Unicode__Map8_recode8':
Map8.xs:358:50: error: passing argument 6 of 'map8_recode_8' from incompatible pointer type [-Wincompatible-pointer-types]
  358 |             map8_recode_8(m1, m2, str, res, len, &rlen);
      |                                                  ^~~~~
      |                                                  |
      |                                                  STRLEN * {aka long unsigned int *}
In file included from Map8.xs:24:
map8.h:83:50: note: expected 'int *' but argument is of type 'STRLEN *' {aka 'long unsigned int *'}
   83 | U8*   map8_recode_8(Map8*, Map8*, U8*, U8*, int, int*);
      |                                                  ^~~~

--- map8.h.orig	2026-11-04 06:26:52.211279434 +0000
+++ map8.h
@@ -80,7 +80,7 @@ U8*   map8_to_str8 (Map8*, U16*, U8*, int, int*);
 
 U16*  map8_to_str16(Map8*, U8*, U16*, int, int*);
 U8*   map8_to_str8 (Map8*, U16*, U8*, int, int*);
-U8*   map8_recode_8(Map8*, Map8*, U8*, U8*, int, int*);
+U8*   map8_recode_8(Map8*, Map8*, U8*, U8*, int, STRLEN*);
 
 int   map8_empty_block(Map8*, U8);
 
