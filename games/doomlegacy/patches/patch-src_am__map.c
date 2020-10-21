$NetBSD: patch-src_am__map.c,v 1.2 2020/10/21 11:43:31 micha Exp $

Set automap "zoom in" key to '+'.

This patch was rejected upstream, because it works for my german keyboard
but not for any other layout (patch is as broken as the original code).
https://sourceforge.net/p/doomlegacy/feature-requests/90/

--- src/am_map.c.orig	2018-07-16 09:17:06.000000000 +0000
+++ src/am_map.c
@@ -118,7 +118,9 @@ static byte DWHITE      =    (256-47);
 #define AM_PANUPKEY     KEY_UPARROW
 #define AM_PANRIGHTKEY  KEY_RIGHTARROW
 #define AM_PANLEFTKEY   KEY_LEFTARROW
-#define AM_ZOOMINKEY    '='
+// The documentation specify '+'
+//#define AM_ZOOMINKEY    '='
+#define AM_ZOOMINKEY    '+'
 #define AM_ZOOMOUTKEY   '-'
 #define AM_STARTKEY     KEY_TAB
 #define AM_ENDKEY       KEY_TAB
