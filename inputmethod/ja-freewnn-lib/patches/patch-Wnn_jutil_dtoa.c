$NetBSD: patch-Wnn_jutil_dtoa.c,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Remove unnecessary old style function declarations

--- Wnn/jutil/dtoa.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jutil/dtoa.c
@@ -87,9 +87,6 @@ int input_comment FRWNN_PARAMS((register
 int input_hinsi_list FRWNN_PARAMS((register FILE *));
 void input_dic FRWNN_PARAMS((FILE *));
 
-extern void sort (), output_ujis (), exit1 (), init_jeary (), get_kanji_str ();
-extern int input_header (), little_endian (), revdic (), wnn_loadhinsi (), init_heap (), w_stradd (), input_hindo_header (), motoni2 ();
-
 #ifdef CONVERT_with_SiSheng
 int input_sisheng FRWNN_PARAMS((register FILE *ifpter));
 #endif	/* CONVERT_with_SiSheng  */
