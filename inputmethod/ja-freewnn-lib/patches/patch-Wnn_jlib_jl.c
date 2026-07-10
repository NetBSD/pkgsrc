$NetBSD: patch-Wnn_jlib_jl.c,v 1.2 2026/07/10 23:32:37 tsutsui Exp $

- Appease -Wincompatible-pointer-types that are fatal on gcc14 and later
- Remove unnecessary old style declarations for standard C functions

--- Wnn/jlib/jl.c.orig	2015-05-10 01:39:27.000000000 +0000
+++ Wnn/jlib/jl.c
@@ -2623,17 +2623,19 @@ jl_dic_list_e (env, dicinfo)
 
 static int
 sort_func_ws (a, b)
-     register char *a, *b;
+     const void *a, *b;
 {
   int ah, bh, ai, bi, iah, ibh, iai, ibi;
-  ah = ((struct wnn_jdata *) a)->hindo;
-  bh = ((struct wnn_jdata *) b)->hindo;
-  iah = ((struct wnn_jdata *) a)->int_hindo;
-  ibh = ((struct wnn_jdata *) b)->int_hindo;
-  ai = ((struct wnn_jdata *) a)->ima;
-  bi = ((struct wnn_jdata *) b)->ima;
-  iai = ((struct wnn_jdata *) a)->int_ima;
-  ibi = ((struct wnn_jdata *) b)->int_ima;
+  const struct wnn_jdata *ja = a;
+  const struct wnn_jdata *jb = b;
+  ah = ja->hindo;
+  bh = jb->hindo;
+  iah = ja->int_hindo;
+  ibh = jb->int_hindo;
+  ai = ja->ima;
+  bi = jb->ima;
+  iai = ja->int_ima;
+  ibi = jb->int_ima;
 
   if (ai == WNN_IMA_OFF && ah == WNN_ENTRY_NO_USE)
     return (1);
@@ -2677,7 +2679,7 @@ jl_word_search_e (env, dic_no, yomi, jdp
     if_dead_disconnect (env, -1);
   jd = (struct wnn_jdata *) wordrb.buf;
 /*    for(cnt = 0 ; jd[cnt].dic_no != -1; cnt++); */
-  qsort ((char *) jd, cnt, sizeof (struct wnn_jdata), sort_func_ws);
+  qsort (jd, cnt, sizeof (struct wnn_jdata), sort_func_ws);
   *jdp = jd;
   return (cnt);
 }
@@ -2696,7 +2698,7 @@ jl_word_search_by_env_e (env, yomi, jdp)
     if_dead_disconnect (env, -1);
   jd = (struct wnn_jdata *) wordrb.buf;
 /*    for(cnt = 0 ; jd[cnt].dic_no != -1; cnt++); */
-  qsort ((char *) jd, cnt, sizeof (struct wnn_jdata), sort_func_ws);
+  qsort (jd, cnt, sizeof (struct wnn_jdata), sort_func_ws);
   *jdp = jd;
   return (cnt);
 }
@@ -2971,7 +2973,6 @@ expand_expr_all (s, env)
 static char *
 getlogname ()
 {
-  struct passwd *getpwuid ();
   return getpwuid (getuid ())->pw_name;
 }
 
@@ -2988,8 +2989,6 @@ expand_expr (s, env)
   char tmp[EXPAND_PATH_LENGTH];
   int noerr, expandsuc;
   struct passwd *u;
-  extern char *getenv ();
-  extern struct passwd *getpwnam ();
 
   if (*s != '~' && *s != '@')
     return (0);
