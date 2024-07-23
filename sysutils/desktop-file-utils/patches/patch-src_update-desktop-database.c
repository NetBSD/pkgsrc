$NetBSD: patch-src_update-desktop-database.c,v 1.2 2024/07/23 06:23:42 adam Exp $

From OpenBSD ports, "Unveil the required directory with .desktop
files and where the cache file needs to be written out to."

--- src/update-desktop-database.c.orig	2023-10-05 15:07:13.000000000 +0000
+++ src/update-desktop-database.c
@@ -456,7 +456,7 @@ main (int    argc,
    };
 
 #ifdef HAVE_PLEDGE
-  if (pledge ("stdio rpath wpath cpath fattr", NULL) == -1) {
+  if (pledge ("stdio rpath wpath cpath fattr unveil", NULL) == -1) {
     g_printerr ("pledge\n");
     return 1;
   }
@@ -487,9 +487,19 @@ main (int    argc,
 
   print_desktop_dirs (desktop_dirs);
 
+#ifdef HAVE_PLEDGE
+  if (unveil ("@LOCALBASE@/share/locale/locale.alias", "r") == -1) {
+    g_printerr ("Can't unveil '@LOCALBASE@/share/locale/locale.alias': %s\n", g_strerror(errno));
+  }
+#endif
   found_processable_dir = FALSE;
   for (i = 0; desktop_dirs[i] != NULL; i++)
     {
+#ifdef HAVE_PLEDGE
+      if (unveil (desktop_dirs[i], "rwc") == -1) {
+        g_printerr ("Can't unveil '%s' directory: %s\n", desktop_dirs[i], g_strerror(errno));
+      }
+#endif
       error = NULL;
       update_database (desktop_dirs[i], &error);
 
@@ -505,6 +515,12 @@ main (int    argc,
     }
   g_option_context_free (context);
 
+#ifdef HAVE_PLEDGE
+  if (unveil (NULL, NULL) == -1) {
+    g_printerr ("unveil\n");
+  }
+#endif
+
   if (!found_processable_dir)
     {
       char *directories;
