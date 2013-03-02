$NetBSD: patch-dirname.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- dirname.c.orig	1995-10-19 15:20:21.000000000 +0000
+++ dirname.c
@@ -66,8 +66,7 @@ char *links_to_path();
  * update_dirname_menu - Update directory name menu for "host" in main
  *                       window.
  */
-update_dirname_menu(host)
-int host;
+void update_dirname_menu(int host)
 {
 	XmString label;
 	char **wd_links;
