$NetBSD: patch-src_am__map.c,v 1.1 2019/06/17 13:53:22 micha Exp $

Set automap "zoom in" key to '+'.

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
