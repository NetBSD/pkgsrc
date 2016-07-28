$NetBSD: patch-ztrack.c,v 1.1 2016/07/28 17:51:20 kamil Exp $

Add explicit braces to avoid ambiguous 'else' (pointed out by -Wall)

--- ztrack.c.orig	1995-12-01 02:34:36.000000000 +0000
+++ ztrack.c
@@ -553,12 +553,13 @@ int f,l=0,r=0;
 
 for(f=0;f<MAX_ENEMY;f++)
   if(enemy[f].active)
-    if(FIX_DOWN(enemy[f].ypos)==0)
+    if(FIX_DOWN(enemy[f].ypos)==0) {
       if(enemy[f].lane==lane-1)
         l=1;
       else
         if(enemy[f].lane==lane+1)
           r=1;
+    }
 
 use_colour(COLOR_YELLOW,A_BOLD);
 
