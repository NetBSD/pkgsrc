$NetBSD: patch-src_update-desktop-database.c,v 1.1 2020/09/01 10:21:55 schmonz Exp $

From OpenBSD ports, "Unveil the required directory with .desktop
files and where the cache file needs to be written out to."

--- src/update-desktop-database.c.orig	Thu Jan  1 00:00:00 1970
+++ src/update-desktop-database.c
@@ -451,8 +451,8 @@ main (int    argc,
      { NULL }
    };
 
-#if HAVE_PLEDGE
-  if (pledge("stdio rpath wpath cpath fattr", NULL) == -1) {
+#ifdef HAVE_PLEDGE
+  if (pledge ("stdio rpath wpath cpath fattr unveil", NULL) == -1) {
     g_printerr ("pledge\n");
     return 1;
   }
@@ -478,9 +478,19 @@ main (int    argc,
 
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
 
@@ -495,6 +505,12 @@ main (int    argc,
         found_processable_dir = TRUE;
     }
   g_option_context_free (context);
+
+#ifdef HAVE_PLEDGE
+  if (unveil (NULL, NULL) == -1) {
+    g_printerr ("unveil\n");
+  }
+#endif
 
   if (!found_processable_dir)
     {
