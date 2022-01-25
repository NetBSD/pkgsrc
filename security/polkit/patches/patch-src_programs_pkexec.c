$NetBSD: patch-src_programs_pkexec.c,v 1.3 2022/01/25 19:40:46 wiz Exp $

gfdwalk: Avoid conflict with SunOS function.

rest:
Fix for CVE-2021-4034.
https://gitlab.freedesktop.org/polkit/polkit/-/commit/a2bf5c9c83b6ae46cbd5c779d3055bff81ded683

--- src/programs/pkexec.c.orig	2018-05-31 11:52:53.000000000 +0000
+++ src/programs/pkexec.c
@@ -245,7 +245,7 @@ set_close_on_exec (gint     fd,
 }
 
 static gboolean
-fdwalk (FdCallback callback,
+gfdwalk (FdCallback callback,
         gpointer   user_data)
 {
   gint fd;
@@ -488,6 +488,15 @@ main (int argc, char *argv[])
   pid_t pid_of_caller;
   gpointer local_agent_handle;
 
+
+  /*
+   * If 'pkexec' is called THIS wrong, someone's probably evil-doing. Don't be nice, just bail out.
+   */
+  if (argc<1)
+    {
+      exit(127);
+    }
+
   ret = 127;
   authority = NULL;
   subject = NULL;
@@ -614,10 +623,10 @@ main (int argc, char *argv[])
 
       path = g_strdup (pwstruct.pw_shell);
       if (!path)
-	{
+        {
           g_printerr ("No shell configured or error retrieving pw_shell\n");
           goto out;
-	}
+        }
       /* If you change this, be sure to change the if (!command_line)
 	 case below too */
       command_line = g_strdup (path);
@@ -636,7 +645,15 @@ main (int argc, char *argv[])
           goto out;
         }
       g_free (path);
-      argv[n] = path = s;
+      path = s;
+
+      /* argc<2 and pkexec runs just shell, argv is guaranteed to be null-terminated.
+       * /-less shell shouldn't happen, but let's be defensive and don't write to null-termination
+       */
+      if (argv[n] != NULL)
+      {
+        argv[n] = path;
+      }
     }
   if (access (path, F_OK) != 0)
     {
@@ -918,7 +935,7 @@ main (int argc, char *argv[])
     }
 
   /* set close_on_exec on all file descriptors except stdin, stdout, stderr */
-  if (!fdwalk (set_close_on_exec, GINT_TO_POINTER (3)))
+  if (!gfdwalk (set_close_on_exec, GINT_TO_POINTER (3)))
     {
       g_printerr ("Error setting close-on-exec for file desriptors\n");
       goto out;
