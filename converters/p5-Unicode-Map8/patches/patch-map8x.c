$NetBSD: patch-map8x.c,v 1.1 2026/11/04 15:10:53 wiz Exp $

In file included from map8x.c:8:
map8.h:83:7: note: previous declaration of 'map8_recode8' with type 'U8 *(Map8 *, Map8 *, U8 *, U8 *, int,  STRLEN *)' {aka 'unsigned char *(struct map8 *, struct map8 *, unsigned char *, unsigned char *, int,  long unsigned int *)'}
   83 | U8*   map8_recode8(Map8*, Map8*, U8*, U8*, int, STRLEN*);
      |       ^~~~~~~~~~~~

--- map8x.c.orig	2026-11-04 15:08:10.519463521 +0000
+++ map8x.c
@@ -307,7 +307,7 @@ U8* map8_to_str8(Map8* m, U16* str16, U8* str8, int le
 #endif  /* !PERL */
 
 
-U8* map8_recode8(Map8* m1, Map8* m2, U8* from, U8* to, int len, int* rlen)
+U8* map8_recode8(Map8* m1, Map8* m2, U8* from, U8* to, int len, STRLEN* rlen)
 {
   dTHX;
   U8* tmp;
