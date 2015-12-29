$NetBSD: patch-splitmrp.c,v 1.2 2015/12/29 04:04:32 dholland Exp $

--- splitmrb.c.orig	2005-11-17 12:19:38.000000000 +0100
+++ splitmrb.c	2012-03-02 13:05:31.593391213 +0100
@@ -237,9 +237,9 @@ int GetPackedByte(FILE *f) // RulLen dec
 #endif
 typedef struct
 {
-  u_int8_t c1,c2,c3;
-  u_int16_t x,y,w,h;
-  u_int32_t hash;
+  uint8_t c1,c2,c3;
+  uint16_t x,y,w,h;
+  uint32_t hash;
 } HOTSPOT
 #if defined(__GNUC__) && __GNUC__ < 3
 __attribute__((packed))
