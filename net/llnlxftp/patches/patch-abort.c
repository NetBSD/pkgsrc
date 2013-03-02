$NetBSD: patch-abort.c,v 1.1 2013/03/02 17:59:40 joerg Exp $

--- abort.c.orig	2013-03-01 13:49:25.000000000 +0000
+++ abort.c
@@ -56,6 +56,8 @@
 #include <Xm/Label.h>
 #include <Xm/ToggleB.h>
 
+static void create_abort_dialog(void);
+
 static Widget w_abortDialog;
 
 extern Widget w_toplev;
@@ -88,7 +90,7 @@ hide_abort_dialog()
  * create_abort_dialog - Creates a dialog that displays an abort-in-progress
  *                       message.
  */
-create_abort_dialog()
+static void create_abort_dialog(void)
 {
 	static int initialized = False;
 	Arg args[1];
