$NetBSD: patch-uip_folder.c,v 1.1 2012/08/31 00:50:05 schnoebe Exp $

Promote the changing of directory to restore the functionality of
``folder -r''

Reported as 37230 (https://savannah.nongnu.org/bugs/index.php?37230)

--- uip/folder.c.orig	2012-06-11 04:06:19.000000000 +0000
+++ uip/folder.c
@@ -341,13 +341,13 @@ main (int argc, char **argv)
     /*
      * Scan the folders
      */
+    /* change directory to base of nmh directory for crawl_folders */
+    if (chdir (nmhdir) == NOTOK)
+	adios (nmhdir, "unable to change directory to");
     if (all || ftotal > 0) {
 	/*
 	 * If no folder is given, do them all
 	 */
-	/* change directory to base of nmh directory for crawl_folders */
-	if (chdir (nmhdir) == NOTOK)
-	    adios (nmhdir, "unable to change directory to");
 	if (!argfolder) {
 	    if (msg)
 		admonish (NULL, "no folder given for message %s", msg);
