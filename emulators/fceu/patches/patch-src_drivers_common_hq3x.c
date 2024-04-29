$NetBSD: patch-src_drivers_common_hq3x.c,v 1.1 2024/04/29 07:52:16 nia Exp $

Make these functions static and let the compiler make decisions about
inlining.  Fixes linking problems when built with modern GCC.

--- src/drivers/common/hq3x.c.orig	2024-04-15 16:53:41.787889567 +0000
+++ src/drivers/common/hq3x.c
@@ -33,17 +33,17 @@ static const  int   trY   = 0x00300000;
 static const  int   trU   = 0x00000700;
 static const  int   trV   = 0x00000006;
 
-inline void Interp1(unsigned char * pc, int c1, int c2)
+static void Interp1(unsigned char * pc, int c1, int c2)
 {
   *((int*)pc) = (c1*3+c2) >> 2;
 }
 
-inline void Interp2(unsigned char * pc, int c1, int c2, int c3)
+static void Interp2(unsigned char * pc, int c1, int c2, int c3)
 {
   *((int*)pc) = (c1*2+c2+c3) >> 2;
 }
 
-inline void Interp3(unsigned char * pc, int c1, int c2)
+static void Interp3(unsigned char * pc, int c1, int c2)
 {
   //*((int*)pc) = (c1*7+c2)/8;
 
@@ -51,7 +51,7 @@ inline void Interp3(unsigned char * pc, 
                  (((c1 & 0xFF00FF)*7 + (c2 & 0xFF00FF) ) & 0x07F807F8)) >> 3;
 }
 
-inline void Interp4(unsigned char * pc, int c1, int c2, int c3)
+static void Interp4(unsigned char * pc, int c1, int c2, int c3)
 {
   //*((int*)pc) = (c1*2+(c2+c3)*7)/16;
 
@@ -59,7 +59,7 @@ inline void Interp4(unsigned char * pc, 
                  (((c1 & 0xFF00FF)*2 + ((c2 & 0xFF00FF) + (c3 & 0xFF00FF))*7 ) & 0x0FF00FF0)) >> 4;
 }
 
-inline void Interp5(unsigned char * pc, int c1, int c2)
+static void Interp5(unsigned char * pc, int c1, int c2)
 {
   *((int*)pc) = (c1+c2) >> 1;
 }
