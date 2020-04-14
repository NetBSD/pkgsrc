$NetBSD: patch-libgnucash_core-utils_binreloc.c,v 1.1 2020/04/14 10:35:17 wiz Exp $

Bugfix for 3.10 release.
https://bugs.gnucash.org/show_bug.cgi?id=797679

--- libgnucash/core-utils/binreloc.c.orig	2020-04-11 21:17:58.000000000 +0000
+++ libgnucash/core-utils/binreloc.c
@@ -475,7 +475,7 @@ find_component_directory (const gchar *d
     prefix = gnc_gbr_find_prefix (NULL);
     if (prefix == NULL)
         return g_strdup (default_dir ? default_dir : compiled_dir);
-    if (!g_getenv("GNC_UNINSTALLE"))
+    if (!g_getenv("GNC_UNINSTALLED"))
     {
         if (!g_strcmp0 (prefix, PREFIX))
             return g_strdup (compiled_dir);
