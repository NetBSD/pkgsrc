$NetBSD: patch-win_jtp_winjtp.c,v 1.3 2012/12/15 11:50:48 marino Exp $

--- win/jtp/winjtp.c.orig	2012-11-19 00:35:09.000000000 +0000
+++ win/jtp/winjtp.c
@@ -1,6 +1,7 @@
 /*	SCCS Id: @(#)winjtp.c	3.0	2000/11/12	*/
 /* Copyright (c) Jaakko Peltonen, 2000				  */
 /* NetHack may be freely redistributed.  See license for details. */
+#include <ctype.h>
 
 #include "hack.h"
 #include "dlb.h"
@@ -1504,12 +1505,12 @@ menu_item **menu_list;
   if (!tempwindow)
   {
     jtp_messagebox("ERROR: Can't find window for menu selection!");
-    return;
+    return -1;
   }  
   if (!tempwindow->menu)
   { 
     jtp_messagebox("ERROR: Window does not have a menu!");
-    return;
+    return -1;
   }  
 
   tempwindow->menu->selectiontype = how;
