$NetBSD: patch-src_xwindisp.c,v 1.1 2016/06/11 18:41:56 kamil Exp $

Fix build issue on NetBSD. I don't know what is sighandler(0).

--- src/xwindisp.c.orig	2000-09-28 11:03:56.000000000 +0000
+++ src/xwindisp.c
@@ -1281,8 +1281,9 @@ xWin_display_cycle()
         break;
 
       case 'd':
-        sighandler(0);                /* ??? debugState = STEP; *//* stepping =
+        /*sighandler(0);*/                /* ??? debugState = STEP; *//* stepping =
                                  * FALSE; */
+        fprintf(stderr, "unsupported");
         break;
 
       case '>':
