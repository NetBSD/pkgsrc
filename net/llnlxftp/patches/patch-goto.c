$NetBSD: patch-goto.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- goto.c.orig	1995-10-19 15:20:22.000000000 +0000
+++ goto.c
@@ -126,8 +126,7 @@ int host;
  * update_goto_menu - Update the "Go to Previous Directory" menu with the
  *                    latest values from the directory cache.
  */
-update_goto_menu(host)
-int host;
+static void update_goto_menu(int host)
 {
 	int i;
 	struct sl_struct *list;
