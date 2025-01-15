$NetBSD: patch-src_programs_pkexec.c,v 1.5 2025/01/15 08:41:38 adam Exp $

gfdwalk: Avoid conflict with SunOS function.

--- src/programs/pkexec.c.orig	2024-08-08 13:12:35.000000000 +0000
+++ src/programs/pkexec.c
@@ -247,8 +247,8 @@ set_close_on_exec (gint     fd,
 }
 
 static gboolean
-fdwalk (FdCallback callback,
-        gpointer   user_data)
+gfdwalk (FdCallback callback,
+         gpointer   user_data)
 {
   gint fd;
   gint max_fd;
@@ -958,7 +958,7 @@ main (int argc, char *argv[])
     }
 
   /* set close_on_exec on all file descriptors except stdin, stdout, stderr */
-  if (!fdwalk (set_close_on_exec, GINT_TO_POINTER (3)))
+  if (!gfdwalk (set_close_on_exec, GINT_TO_POINTER (3)))
     {
       g_printerr ("Error setting close-on-exec for file descriptors\n");
       goto out;
