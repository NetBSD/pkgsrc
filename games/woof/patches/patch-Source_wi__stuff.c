$NetBSD: patch-Source_wi__stuff.c,v 1.1 2021/08/23 14:27:43 micha Exp $

Workaround for namespace clash on SmartOS:

/home/pbulk/build/games/woof/work/woof-woof_6.3.1/Source/wi_stuff.c:366:19: error: 'time' redeclared as different kind of symbol
  366 | static patch_t*   time;
      |                   ^~~~

--- Source/wi_stuff.c.orig	2021-08-13 13:18:32.000000000 +0000
+++ Source/wi_stuff.c
@@ -363,7 +363,7 @@ static patch_t*   items;
 static patch_t*   frags;
 
 // Time sucks.
-static patch_t*   time;
+static patch_t*   woof_time;
 static patch_t*   par;
 static patch_t*   sucks;
 
@@ -897,7 +897,7 @@ static void WI_unloadData(void)
   Z_ChangeTag(sp_secret, PU_CACHE);
   Z_ChangeTag(items, PU_CACHE);
   Z_ChangeTag(frags, PU_CACHE);
-  Z_ChangeTag(time, PU_CACHE);
+  Z_ChangeTag(woof_time, PU_CACHE);
   Z_ChangeTag(sucks, PU_CACHE);
   Z_ChangeTag(par, PU_CACHE);
 
@@ -1815,7 +1815,7 @@ static void WI_drawStats(void)
   V_DrawPatch(SP_STATSX, SP_STATSY+2*lh, FB, sp_secret);
   WI_drawPercent(ORIGWIDTH - SP_STATSX, SP_STATSY+2*lh, cnt_secret[0]);
 
-  V_DrawPatch(SP_TIMEX, SP_TIMEY, FB, time);
+  V_DrawPatch(SP_TIMEX, SP_TIMEY, FB, woof_time);
   WI_drawTime(ORIGWIDTH/2 - SP_TIMEX, SP_TIMEY, cnt_time, true);
 
   // Ty 04/11/98: redid logic: should skip only if with pwad but 
@@ -2077,7 +2077,7 @@ void WI_loadData(void)
   colon = W_CacheLumpName("WICOLON", PU_STATIC); 
 
   // "time"
-  time = W_CacheLumpName("WITIME", PU_STATIC);   
+  woof_time = W_CacheLumpName("WITIME", PU_STATIC);   
 
   // "sucks"
   sucks = W_CacheLumpName("WISUCKS", PU_STATIC);  
