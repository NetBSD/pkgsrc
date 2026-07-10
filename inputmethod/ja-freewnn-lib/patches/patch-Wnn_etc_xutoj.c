$NetBSD: patch-Wnn_etc_xutoj.c,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Fix old style function prototypes for -std=gnu23

--- Wnn/etc/xutoj.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/etc/xutoj.c
@@ -765,13 +765,13 @@ putsjw (x)
 }
 
 static int oj_mode = ASCII;     /* 出力時のｊｉｓコードのモード */
-static int jtosj ();
-extern int eujis_to_iujis ();
+static int jtosj FRWNN_PARAMS((unsigned int, unsigned int));
+static int sjtoj FRWNN_PARAMS((unsigned int, unsigned int));
 
 /* convert JIS code to shift-JIS code */
 static int
 jtosj (high, low)
-     unsigned high, low;
+     unsigned int high, low;
 {
   if (high & 1)
     low += 0x1f;
@@ -788,7 +788,7 @@ jtosj (high, low)
 /* convert shift-JIS to JIS code */
 static int
 sjtoj (high, low)
-     register unsigned high, low;
+     register unsigned int high, low;
 {
   high -= (high <= 0x9f) ? 0x71 : 0xb1;
   high = high * 2;
