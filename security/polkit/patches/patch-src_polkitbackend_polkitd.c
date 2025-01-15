$NetBSD: patch-src_polkitbackend_polkitd.c,v 1.3 2025/01/15 08:41:38 adam Exp $

Avoid %m usage in printf.

--- src/polkitbackend/polkitd.c.orig	2025-01-13 14:54:22.000000000 +0000
+++ src/polkitbackend/polkitd.c
@@ -20,6 +20,7 @@
  */
 
 #include <signal.h>
+#include <errno.h>
 #include <stdlib.h>
 
 #include <glib-unix.h>
@@ -148,7 +149,7 @@ become_user (const gchar  *user,
   if (pw == NULL)
     {
       g_set_error (error, G_IO_ERROR, G_IO_ERROR_FAILED,
-                   "Error calling getpwnam(): %m");
+                   "Error calling getpwnam(): %s", g_strerror(errno));
       goto out;
     }
 
@@ -163,13 +164,13 @@ become_user (const gchar  *user,
   if (setgroups (0, NULL) != 0)
     {
       g_set_error (error, G_IO_ERROR, G_IO_ERROR_FAILED,
-                   "Error clearing groups: %m");
+                   "Error clearing groups: %s", g_strerror(errno));
       goto out;
     }
   if (initgroups (pw->pw_name, pw->pw_gid) != 0)
     {
       g_set_error (error, G_IO_ERROR, G_IO_ERROR_FAILED,
-                   "Error initializing groups: %m");
+                   "Error initializing groups: %s", g_strerror(errno));
       goto out;
     }
 
@@ -179,16 +180,16 @@ become_user (const gchar  *user,
       (getegid () != pw->pw_gid) || (getgid () != pw->pw_gid))
     {
       g_set_error (error, G_IO_ERROR, G_IO_ERROR_FAILED,
-                   "Error becoming real+effective uid %d and gid %d: %m",
-                   (int) pw->pw_uid, (int) pw->pw_gid);
+                   "Error becoming real+effective uid %d and gid %d: %s",
+                   (int) pw->pw_uid, (int) pw->pw_gid, g_strerror(errno));
       goto out;
     }
 
   if (chdir ("/") != 0)
     {
       g_set_error (error, G_IO_ERROR, G_IO_ERROR_FAILED,
-                   "Error changing to root directory %s: %m",
-                   pw->pw_dir);
+                   "Error changing to root directory %s: %s",
+                   pw->pw_dir, g_strerror(errno));
       goto out;
     }
 
@@ -245,7 +246,7 @@ main (int    argc,
         }
       else
         {
-          g_warning ("Error opening /dev/null: %m");
+          g_warning ("Error opening /dev/null: %s", g_strerror(errno));
         }
     }
 
