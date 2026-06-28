$NetBSD: patch-Wnn_include_jutil.h,v 1.1 2026/06/28 06:16:27 tsutsui Exp $

- Fix build with -std=gnu23 (i.e. gcc14 and later)

--- Wnn/include/jutil.h.orig	2014-08-01 22:04:26.000000000 +0000
+++ Wnn/include/jutil.h
@@ -40,6 +40,8 @@
 #define FRWNN_PARAMS(paramlist)	()
 #endif	/* __STDC__ */
 
+typedef int (*WNN_CompareFunc)(const void *, const void *);
+
 /* -- macro  -- */
 /* ujisf.c  */
 #define WNN_HINSI_LEN 4096
@@ -86,17 +88,17 @@ extern void output_ujis FRWNN_PARAMS((re
 extern int init_heap FRWNN_PARAMS((int, int, int, int, FILE *));
 extern void init_jeary FRWNN_PARAMS((void));
 extern void exit1 FRWNN_PARAMS((void));
-extern int sort_func_je FRWNN_PARAMS((char *, char *));
-extern int sort_func_je_kanji FRWNN_PARAMS((char *, char *));
-extern int sort_func FRWNN_PARAMS((register char *, register char *, int));
+extern int sort_func_je FRWNN_PARAMS((const void *, const void *));
+extern int sort_func_je_kanji FRWNN_PARAMS((const void *, const void *));
+extern int sort_func FRWNN_PARAMS((const void *, const void *, int));
 extern void sort FRWNN_PARAMS((void));
 extern void sort_if_not_sorted FRWNN_PARAMS((void));
 extern void sort_kanji FRWNN_PARAMS((void));
-extern void uniq_je FRWNN_PARAMS((int (*) ()));
+extern void uniq_je FRWNN_PARAMS((WNN_CompareFunc));
 #ifdef nodef
 extern int make_kanji_str FRWNN_PARAMS((register UCHAR *, register UCHAR *));
 #endif	/* nodef  */
-extern int Sorted FRWNN_PARAMS((register char *, register int, int, int (*) ()));
+extern int Sorted FRWNN_PARAMS((const void *, register int, int, WNN_CompareFunc));
 extern int is_katakana FRWNN_PARAMS((register char *, register char *));
 
 /* dic_head.c */
