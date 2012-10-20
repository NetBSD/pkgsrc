$NetBSD: patch-atk-adaptor_accessible-cache.c,v 1.1 2012/10/20 22:06:18 joerg Exp $

--- atk-adaptor/accessible-cache.c.orig	2012-10-20 10:30:48.000000000 +0000
+++ atk-adaptor/accessible-cache.c
@@ -362,7 +362,7 @@ child_added_listener (GSignalInvocationH
           if (!child)
             {
               g_static_rec_mutex_unlock (&cache_mutex);
-              return;
+              return TRUE;
             }
 
           g_object_ref (child);
