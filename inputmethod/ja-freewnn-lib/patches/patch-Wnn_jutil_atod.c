$NetBSD: patch-Wnn_jutil_atod.c,v 1.2 2026/07/10 23:32:37 tsutsui Exp $

- Appease -Wincompatible-pointer-types that are fatal on gcc14 and later

--- Wnn/jutil/atod.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jutil/atod.c
@@ -76,7 +76,7 @@ static char *rcs_id = "$Id: atod.c,v 1.1
 extern int wnn_loadhinsi FRWNN_PARAMS((unsigned char*)),
   init_heap FRWNN_PARAMS((int,int,int,int,FILE*)),
   little_endian FRWNN_PARAMS(()),
-  Sorted FRWNN_PARAMS((register char*,register int,int,int (*sort_fun)(char*,char*))),
+  Sorted FRWNN_PARAMS((const void*,register int,int,WNN_CompareFunc)),
   asshuku FRWNN_PARAMS((int)),
   revdic FRWNN_PARAMS((struct JT *,int));
 #ifdef CHINESE
@@ -87,7 +87,7 @@ extern void ujis_header FRWNN_PARAMS((vo
 extern void read_ujis FRWNN_PARAMS((int,int,int)),
   reverse_yomi FRWNN_PARAMS((void)),
   create_rev_dict FRWNN_PARAMS((void)),
-  uniq_je FRWNN_PARAMS((int(*func)(char*,char*))),
+  uniq_je FRWNN_PARAMS((WNN_CompareFunc)),
   sort_if_not_sorted FRWNN_PARAMS((void)),
   output_header FRWNN_PARAMS((FILE*,struct JT*,struct wnn_file_head*)),
   udytoS FRWNN_PARAMS((w_char*,int,char*,struct uind1*)),
@@ -97,8 +97,8 @@ extern void read_ujis FRWNN_PARAMS((int,
   rev_short_fun FRWNN_PARAMS((w_char*)),
   rev_w_char FRWNN_PARAMS((w_char*,int));
 
-extern int sort_func_sdic FRWNN_PARAMS((char*,char*));
-extern int sort_func_je FRWNN_PARAMS((char*,char*));
+extern int sort_func_sdic FRWNN_PARAMS((const void*,const void*));
+extern int sort_func_je FRWNN_PARAMS((const void*,const void*));
 extern void set_cswidth FRWNN_PARAMS((register unsigned int));
 
 static void ujistoud FRWNN_PARAMS((void)),
@@ -573,12 +573,12 @@ yStrcmp (w_char* a, w_char*b)
 }
 
 int
-sort_func_sdic (char* a, char* b)
+sort_func_sdic (const void* a, const void* b)
 {
   int tmp;
   struct je *pa, *pb;
-  pa = *((struct je **) a);
-  pb = *((struct je **) b);
+  pa = *((struct je * const *) a);
+  pb = *((struct je * const *) b);
   tmp = yStrcmp (pa->yomi, pb->yomi);
   if (tmp)
     return (tmp);
@@ -595,9 +595,9 @@ sort_func_sdic (char* a, char* b)
 static void
 sdic_sort (void)
 {
-  if (!Sorted ((char *) jeary, (int) jt.maxserial, sizeof (struct je *), sort_func_sdic))
+  if (!Sorted (jeary, (int) jt.maxserial, sizeof (struct je *), sort_func_sdic))
     {
-      qsort ((char *) jeary, (int) jt.maxserial, sizeof (struct je *), sort_func_sdic);
+      qsort (jeary, (int) jt.maxserial, sizeof (struct je *), sort_func_sdic);
     }
 }
 
