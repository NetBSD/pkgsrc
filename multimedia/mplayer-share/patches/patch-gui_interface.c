$NetBSD: patch-gui_interface.c,v 1.1 2014/10/09 14:48:51 martin Exp $

Add missing global variable to avoid link error.

--- gui/interface.c.orig	2012-05-21 20:46:25.000000000 +0200
+++ gui/interface.c	2014-10-09 16:10:41.000000000 +0200
@@ -62,6 +62,7 @@ guiInterface_t guiInfo = {
 };
 
 static int initialized;
+int dvd_angle = 1;
 
 /* MPlayer -> GUI */
 
