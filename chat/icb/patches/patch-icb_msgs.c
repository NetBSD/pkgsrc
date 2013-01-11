$NetBSD: patch-icb_msgs.c,v 1.1 2013/01/11 13:24:32 joerg Exp $

--- icb/msgs.c.orig	1995-02-24 21:20:24.000000000 +0000
+++ icb/msgs.c
@@ -3,6 +3,7 @@
 
 /* handle various messages from the server */
 
+#include <ctype.h>
 #include <stdio.h>
 #include "icb.h"
 #include "externs.h"
@@ -17,8 +18,7 @@
 
 /* open message */
 
-copenmsg(pkt)
-char *pkt;
+void copenmsg(char *pkt)
 {
 	if (split(pkt) != 2) {
 		putl("[=Error=] got bad open message packet", PL_ALL);
@@ -38,8 +38,7 @@ char *pkt;
 
 /* personal message */
 
-cpersonalmsg(pkt)
-char *pkt;
+void cpersonalmsg(char *pkt)
 {
 	char string[256];
 	char host[256];
@@ -66,8 +65,7 @@ char *pkt;
 
 /* beep message */
 
-beep(pkt)
-char *pkt;
+void beep(char *pkt)
 {
 	char nick[MAX_NICKLEN+1];
 
@@ -110,8 +108,7 @@ exitmsg()
 
 /* protocol version message */
 
-protomsg(pkt)
-char *pkt;
+void protomsg(char *pkt)
 {
 	char *p;
 	int proto_level;
@@ -168,8 +165,7 @@ char *pkt;
 
 /* system status update message */
 
-statusmsg(pkt)
-char *pkt;
+void statusmsg(char *pkt)
 {
 	if (split(pkt) != 2) {
 		putl("[=Error=] got bad status message packet", PL_ALL);
@@ -329,8 +325,7 @@ char *pkt;
 
 /* important system message */
 
-importantmsg(pkt)
-char *pkt;
+void importantmsg(char *pkt)
 {
 	if (split(pkt) != 2) {
 		putl("[=Error=] got bad \"important\" message packet", PL_ALL);
