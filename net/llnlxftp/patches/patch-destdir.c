$NetBSD: patch-destdir.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- destdir.c.orig	2013-03-01 13:55:32.000000000 +0000
+++ destdir.c
@@ -104,7 +104,7 @@ char *cstring_to_text();
  * create_destdir_dialog - Create dialog that prompts for destination
  *                         directory.
  */
-create_destdir_dialog()
+static void create_destdir_dialog(void)
 {
 	static int initialized = False;
     XmString label;
