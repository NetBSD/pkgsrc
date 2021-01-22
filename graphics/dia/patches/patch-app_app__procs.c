$NetBSD: patch-app_app__procs.c,v 1.1.2.2 2021/01/22 18:11:31 bsiegert Exp $

Fix endless loop on filenames with invalid encoding (CVE-2019-19451)
https://gitlab.gnome.org/GNOME/dia/issues/428

--- app/app_procs.c.orig	2014-08-24 15:46:01.000000000 +0000
+++ app/app_procs.c
@@ -801,6 +801,7 @@ app_init (int argc, char **argv)
 
 	if (!filename) {
 	  g_print (_("Filename conversion failed: %s\n"), filenames[i]);
+	  ++i;
 	  continue;
 	}
 
