$NetBSD: patch-Wnn_jutil_ujisf.c,v 1.4 2026/07/10 23:32:37 tsutsui Exp $

- Appease -Wincompatible-pointer-types that are fatal on gcc14 and later
- Remove unnecessary old style function declaration

--- Wnn/jutil/ujisf.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jutil/ujisf.c
@@ -76,7 +76,6 @@ extern unsigned char kanjiaddr (unsigned
 extern void Print_entry (w_char* yomi, w_char* kstr, w_char* cstr,
 		int hindo, int ima, int hinsi, int serial,
 		FILE* ofpter, int esc_exp);
-extern int  w_stradd ();
 
 static void Kanjistradd FRWNN_PARAMS((w_char *, w_char *, w_char *, register UCHAR **));
 static void bunpou_num FRWNN_PARAMS((register char *, register int *));
@@ -716,27 +715,27 @@ sisheng_num (a, p)
 
 int
 sort_func_je (a, b)
-     char *a, *b;
+     const void *a, *b;
 {
   return (sort_func (a, b, D_YOMI));
 }
 
 int
 sort_func_je_kanji (a, b)
-     char *a, *b;
+     const void *a, *b;
 {
   return (sort_func (a, b, D_KANJI));
 }
 
 int
 sort_func (a, b, which)
-     register char *a, *b;
+     const void *a, *b;
      int which;
 {
   register int tmp;
   register struct je *pa, *pb;
-  pa = *((struct je **) a);
-  pb = *((struct je **) b);
+  pa = *((struct je * const *) a);
+  pb = *((struct je * const *) b);
   if (pa->hinsi == SAKUJO_HINSI)
     {
       if (pb->hinsi == SAKUJO_HINSI)
@@ -808,13 +807,13 @@ sort_func (a, b, which)
 void
 sort ()
 {
-  qsort ((char *) jeary, jt.maxserial, sizeof (struct je *), sort_func_je);
+  qsort (jeary, jt.maxserial, sizeof (struct je *), sort_func_je);
 }
 
 void
 sort_if_not_sorted ()
 {
-  if (!Sorted ((char *) jeary, jt.maxserial, sizeof (struct je *), sort_func_je))
+  if (!Sorted (jeary, jt.maxserial, sizeof (struct je *), sort_func_je))
     {
       sort ();
     }
@@ -823,12 +822,12 @@ sort_if_not_sorted ()
 void
 sort_kanji ()
 {
-  qsort ((char *) jeary, jt.maxserial, sizeof (struct je *), sort_func_je_kanji);
+  qsort (jeary, jt.maxserial, sizeof (struct je *), sort_func_je_kanji);
 }
 
 void
 uniq_je (func)
-     int (*func) ();
+     WNN_CompareFunc func;
 {
   int k;
   struct je **prev, **jep;
@@ -839,7 +838,7 @@ uniq_je (func)
   for (k = 1; k < jt.maxserial; k++)
     {
       jep = &jeary[k];
-      if (func ((char *) jep, (char *) prev) == 0)
+      if (func (jep, prev) == 0)
         {
           w_char tmp[LENGTHYOMI];
           char tmp1[LENGTHYOMI];
@@ -990,15 +989,16 @@ read_kanji_str_w (c, o)
 
 int
 Sorted (st, lc, size, sort_fun)
-     register char *st;
+     const void *st;
      register int lc;
      int size;
-     int (*sort_fun) ();
+     WNN_CompareFunc sort_fun;
 {
-  char *dst = st + size;
-  for (lc--; lc > 0; lc--, st = dst, dst += size)
+  const char *src = st;
+  const char *dst = st + size;
+  for (lc--; lc > 0; lc--, src = dst, dst += size)
     {
-      if (sort_fun (st, dst) > 0)
+      if (sort_fun (src, dst) > 0)
         {
           return (0);
         }
