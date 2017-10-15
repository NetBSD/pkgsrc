$NetBSD: patch-source_tables.c,v 1.1 2017/10/15 03:16:07 maya Exp $

Avoid global buffer overflow

--- source/tables.c.orig	1994-07-22 01:47:47.000000000 +0000
+++ source/tables.c
@@ -13,7 +13,7 @@
 #ifdef MORIA_HOU
 /* Operating hours for Moria				-RAK-	*/
 /*	 X = Open; . = Closed					*/
-char  days[7][29] = { "SUN:XXXXXXXXXXXXXXXXXXXXXXXX",
+char  days[7][30] =  { "SUN:XXXXXXXXXXXXXXXXXXXXXXXX",
 		    "MON:XXXXXXXX.........XXXXXXX",
 		    "TUE:XXXXXXXX.........XXXXXXX",
 		    "WED:XXXXXXXX.........XXXXXXX",
