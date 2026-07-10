$NetBSD: patch-Wnn_etc_bdic.c,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Remove unnecessary old stype function declarations that cause erorrs
  on -std=gnu23

--- Wnn/etc/bdic.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/etc/bdic.c
@@ -857,7 +857,6 @@ get_kanji_str (UCHAR* kptr, w_char* kanj
   w_char *tmpy;
   w_char *tmpk;
   w_char *tmpc;
-  extern void Get_kanji_str_r ();
 
   Get_kanji_str_r (kptr, &tmpk, &tmpy, &tmpc);
 
@@ -1306,7 +1305,6 @@ Print_entry (
   char *k;
   char buf[32];
   static w_char revy[LENGTHKANJI];
-  extern void kanji_esc_str ();
 
   if (serial != -1)
     {
