$NetBSD: patch-mpmonitor.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- mpmonitor.c.orig	1995-10-19 15:20:23.000000000 +0000
+++ mpmonitor.c
@@ -59,6 +59,8 @@
 #include <Xm/Form.h>
 #include <Xm/TextF.h>
 
+void create_mp_monitor_dialog(void);
+
 static int abort_requested;
 
 static struct {
@@ -104,7 +106,7 @@ char *path_label;
  * create_mp_monitor_dialog - Create dialog window that displays the
  *                            directory entry currently being operated on.
  */
-create_mp_monitor_dialog()
+void create_mp_monitor_dialog(void)
 {
 	static int initialized = False;
 	Arg args[1];
