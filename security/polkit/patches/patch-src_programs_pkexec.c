$NetBSD: patch-src_programs_pkexec.c,v 1.4 2023/06/07 15:36:40 wiz Exp $

gfdwalk: Avoid conflict with SunOS function.

--- src/programs/pkexec.c.orig	2022-07-11 08:46:06.000000000 +0000
+++ src/programs/pkexec.c
@@ -245,8 +245,8 @@ set_close_on_exec (gint     fd,
 }
 
 static gboolean
-fdwalk (FdCallback callback,
-        gpointer   user_data)
+gfdwalk (FdCallback callback,
+         gpointer   user_data)
 {
   gint fd;
   gint max_fd;
@@ -941,7 +941,7 @@ main (int argc, char *argv[])
     }
 
   /* set close_on_exec on all file descriptors except stdin, stdout, stderr */
-  if (!fdwalk (set_close_on_exec, GINT_TO_POINTER (3)))
+  if (!gfdwalk (set_close_on_exec, GINT_TO_POINTER (3)))
     {
       g_printerr ("Error setting close-on-exec for file desriptors\n");
       goto out;
