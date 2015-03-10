$NetBSD: patch-src_Types.h,v 1.1 2015/03/10 15:20:17 joerg Exp $

Make sure that PINYIN_ID_VOID is valid on platforms like ARM with
char == unsigned char.

--- src/Types.h.orig	2015-03-10 14:44:24.000000000 +0000
+++ src/Types.h
@@ -26,7 +26,7 @@
 
 namespace PyZy {
 
-#define PINYIN_ID_VOID  (-1)
+#define PINYIN_ID_VOID  ((char)-1)
 #define PINYIN_ID_ZERO  (0)
 #define PINYIN_ID_B     (1)
 #define PINYIN_ID_C     (2)
