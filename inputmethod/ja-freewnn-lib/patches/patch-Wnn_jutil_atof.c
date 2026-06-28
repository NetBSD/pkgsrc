$NetBSD: patch-Wnn_jutil_atof.c,v 1.1 2026/06/28 06:16:28 tsutsui Exp $

- Fix build with -std=gnu23 (i.e. gcc14 and later)

--- Wnn/jutil/atof.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/jutil/atof.c
@@ -596,15 +596,18 @@ read_id ()
 
 static int
 sort_func_id (a, b)
-     char *a, *b;
+     const void *a, *b;
 {
-  return (strcmp (((struct id_struct *) a)->str, ((struct id_struct *) b)->str));
+  const struct id_struct *ia = a;
+  const struct id_struct *ib = b;
+
+  return (strcmp (ia->str, ib->str));
 }
 
 static void
 sort_id ()
 {
-  qsort ((char *) &id[0], id_num, sizeof (struct id_struct), sort_func_id);
+  qsort (&id[0], id_num, sizeof (struct id_struct), sort_func_id);
 }
 
 #ifdef nodef
@@ -741,17 +744,20 @@ bsch (c, st, end)
 #ifndef NO_FZK
 static int
 sort_func_fz (a, b)
-     char *a, *b;
+     const void *a, *b;
 {
   int c;
+  /* XXX may cause -Wcast-qual but wnn_Strcmp() should be fixed to take const */
+  struct fuzokugo *fa = (struct fuzokugo *)a;
+  struct fuzokugo *fb = (struct fuzokugo *)b;
 
-  if ((c = wnn_Strcmp (((struct fuzokugo *) a)->y, ((struct fuzokugo *) b)->y)) == 0)
+  if ((c = wnn_Strcmp (fa->y, fb->y)) == 0)
     {
-      if (((struct fuzokugo *) a)->hinsi > ((struct fuzokugo *) b)->hinsi)
+      if (fa->hinsi > fb->hinsi)
         {
           return (1);
         }
-      else if (((struct fuzokugo *) a)->hinsi < ((struct fuzokugo *) b)->hinsi)
+      else if (fa->hinsi < fb->hinsi)
         {
           return (-1);
         }
@@ -763,7 +769,7 @@ sort_func_fz (a, b)
 static void
 sort ()
 {
-  qsort ((char *) &fz[0], fz_num, sizeof (struct fuzokugo), sort_func_fz);
+  qsort (&fz[0], fz_num, sizeof (struct fuzokugo), sort_func_fz);
 }
 #endif /* NO_FZK */
 
