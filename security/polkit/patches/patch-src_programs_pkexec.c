$NetBSD: patch-src_programs_pkexec.c,v 1.2 2016/06/18 12:16:23 youri Exp $

Avoid conflict with SunOS function.

--- src/programs/pkexec.c.orig	2015-06-18 20:20:50.000000000 +0000
+++ src/programs/pkexec.c
@@ -247,7 +247,7 @@ set_close_on_exec (gint     fd,
 }
 
 static gboolean
-fdwalk (FdCallback callback,
+gfdwalk (FdCallback callback,
         gpointer   user_data)
 {
   gint fd;
@@ -922,7 +922,7 @@ main (int argc, char *argv[])
     }
 
   /* set close_on_exec on all file descriptors except stdin, stdout, stderr */
-  if (!fdwalk (set_close_on_exec, GINT_TO_POINTER (3)))
+  if (!gfdwalk (set_close_on_exec, GINT_TO_POINTER (3)))
     {
       g_printerr ("Error setting close-on-exec for file desriptors\n");
       goto out;
