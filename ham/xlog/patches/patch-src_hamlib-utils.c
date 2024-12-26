$NetBSD: patch-src_hamlib-utils.c,v 1.1 2024/12/26 13:32:39 gdt Exp $

Resolve type error in usage of hamlib function (4.6).

https://savannah.nongnu.org/bugs/index.php?66598

--- src/hamlib-utils.c.orig	2024-12-26 13:23:19.845248277 +0000
+++ src/hamlib-utils.c
@@ -197,7 +197,7 @@ start_hamlib (gint rigid, gchar *device,
 
 /* Append a new entry in the driver list. It is called by rig_list_foreach */
 static gint
-riglist_make_list (const struct rig_caps *caps, gpointer data)
+riglist_make_list (struct rig_caps *caps, gpointer data)
 {
 	rigs = g_list_append (rigs, (gpointer) caps);
 	return 1;		/* !=0, we want them all ! */
