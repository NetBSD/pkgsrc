$NetBSD: patch-src_polkitbackend_polkitd.c,v 1.1 2016/05/20 18:39:33 youri Exp $

Avoid %m usage in printf.

--- src/polkitbackend/polkitd.c.orig	2015-06-18 20:20:50.000000000 +0000
+++ src/polkitbackend/polkitd.c
@@ -22,6 +22,7 @@
 #include "config.h"
 
 #include <signal.h>
+#include <errno.h>
 
 #include <glib-unix.h>
 
@@ -109,20 +110,20 @@ become_user (const gchar  *user,
   if (pw == NULL)
     {
       g_set_error (error, G_IO_ERROR, G_IO_ERROR_FAILED,
-                   "Error calling getpwnam(): %m");
+                   "Error calling getpwnam(): %s", g_strerror(errno));
       goto out;
     }
 
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
 
@@ -132,16 +133,16 @@ become_user (const gchar  *user,
       (getegid () != pw->pw_gid) || (getgid () != pw->pw_gid))
     {
       g_set_error (error, G_IO_ERROR, G_IO_ERROR_FAILED,
-                   "Error becoming real+effective uid %d and gid %d: %m",
-                   (int) pw->pw_uid, (int) pw->pw_gid);
+                   "Error becoming real+effective uid %d and gid %d: %s",
+                   (int) pw->pw_uid, (int) pw->pw_gid, g_strerror(errno));
       goto out;
     }
 
   if (chdir (pw->pw_dir) != 0)
     {
       g_set_error (error, G_IO_ERROR, G_IO_ERROR_FAILED,
-                   "Error changing to home directory %s: %m",
-                   pw->pw_dir);
+                   "Error changing to home directory %s: %s",
+                   pw->pw_dir, g_strerror(errno));
       goto out;
     }
 
@@ -196,7 +197,7 @@ main (int    argc,
         }
       else
         {
-          g_warning ("Error opening /dev/null: %m");
+          g_warning ("Error opening /dev/null: %s", g_strerror(errno));
         }
     }
 
