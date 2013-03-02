$NetBSD: patch-misc.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- misc.c.orig	1995-10-19 15:20:23.000000000 +0000
+++ misc.c
@@ -67,6 +67,8 @@
 
 #define MAXTRIES  10
 
+void disconnect(int host);
+
 struct {
 	unsigned char *data;
 	int width;
@@ -137,8 +139,7 @@ XtPointer call_data;
  * disconnect - Disconnects "host".  The indicated host can be either locally
  *              or remotely connected.
  */
-disconnect(host)
-int host;
+void disconnect(int host)
 {
 	switch (hinfo[host].type) {
 	case NEITHER:
@@ -362,7 +363,7 @@ char *file_path;
  *               try to create either a 50x50 icon or a 64x64 icon, depending
  *               on what size the window manager prefers.
  */
-create_icon()
+void create_icon(void)
 {
     XIconSize *list;
     int count;
