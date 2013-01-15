$NetBSD: patch-events.c,v 1.1 2013/01/15 15:19:05 joerg Exp $

--- events.c.orig	1992-03-29 19:41:27.000000000 +0000
+++ events.c
@@ -4,6 +4,8 @@
 #include "copyright.h"
 #include "defs.h"
 
+int usecdelay = USECDELAY;
+
 /*	event_filter handles game events
 */
 int	event_filter()
@@ -86,6 +88,13 @@ XKeyEvent	*event;
 	
 	XLookupString(event, &buf, 1, &key, &i);
 	switch(key) {
+                case 't':
+                case 'T':
+                       if (usecdelay == USECDELAY)
+                           usecdelay = USECDELAY/1.5;
+                       else
+                           usecdelay = USECDELAY;
+                       break;
 		case XK_KP_4:
 		case 'a':
 		case 'A':
@@ -115,6 +124,7 @@ XKeyEvent	*event;
 			}
 			break;
 		case 'Q':
+	        case 'q':
 			if(dead) break;
 			dead = 1;
 			deadtimer = 50;
@@ -124,6 +134,7 @@ XKeyEvent	*event;
 			dumb_message(MQUIT);
 			break;
 		case 'p':
+		case 'P':
 			if(paused) {
 				paused = 0;
 				bigmessagetime = 0;
