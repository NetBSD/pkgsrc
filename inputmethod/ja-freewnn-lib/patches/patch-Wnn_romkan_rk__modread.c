$NetBSD: patch-Wnn_romkan_rk__modread.c,v 1.1 2026/07/10 23:32:38 tsutsui Exp $

- Use proper function prototypes for -std=gnu23

--- Wnn/romkan/rk_modread.c.orig	2013-09-02 11:01:39.000000000 +0000
+++ Wnn/romkan/rk_modread.c
@@ -67,7 +67,7 @@
 extern char *chrcat FRWNN_PARAMS((char*,char)),
   *strend FRWNN_PARAMS((char*)),
   *ename FRWNN_PARAMS((char*));
-extern void romkan_clear ();
+extern void romkan_clear FRWNN_PARAMS((void));
 char *modhyopath;
 
 static void cond_evl FRWNN_PARAMS((char*)),
@@ -76,8 +76,8 @@ static void cond_evl FRWNN_PARAMS((char*
   rd_ctrl FRWNN_PARAMS((register FILE*,char**)),
   hyouse FRWNN_PARAMS((int)),
   look_choose FRWNN_PARAMS((int**,int));
-void choosehyo ();
-static int mystrcmp FRWNN_PARAMS((char*,char*)),
+  void choosehyo FRWNN_PARAMS((void));
+  static int mystrcmp FRWNN_PARAMS((char*,char*)),
   read1tm FRWNN_PARAMS((char**,int)),
   mod_evl FRWNN_PARAMS((char*)),
   fnmsrc_tourk FRWNN_PARAMS((char*)),
@@ -613,7 +613,7 @@ get_hmdir (dest, soc)
         時3、~のあとに存在しないユーザ名が来たら4。*/
 int
 readfnm (readchar_func, unreadc_func, readstr_func, areap, lastcptr)
-     register int (*readchar_func) (), (*unreadc_func) (), (*readstr_func) ();
+     register int (*readchar_func) FRWNN_PARAMS((void)), (*unreadc_func) FRWNN_PARAMS((int)), (*readstr_func) FRWNN_PARAMS((char **, int));
      char **areap;
      int *lastcptr;
 {
