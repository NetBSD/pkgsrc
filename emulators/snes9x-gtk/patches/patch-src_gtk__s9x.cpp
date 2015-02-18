$NetBSD: patch-src_gtk__s9x.cpp,v 1.1 2015/02/18 08:50:44 wiz Exp $

Fix core dump during startup:
unexpected error from c library during 'pthread_mutex_unlock': operation not permitted
based on patch from FreeBSD ports via Stephen Black in PR 49671.

--- src/gtk_s9x.cpp.orig	2011-04-24 13:38:10.000000000 +0000
+++ src/gtk_s9x.cpp
@@ -44,6 +44,7 @@ main (int argc, char *argv[])
 
     g_thread_init (NULL);
     gdk_threads_init ();
+    gdk_threads_enter();
 
     gtk_init (&argc, &argv);
 
@@ -127,6 +128,8 @@ main (int argc, char *argv[])
 
     gtk_main ();
 
+    gdk_threads_leave();
+    
     return 0;
 }
 
