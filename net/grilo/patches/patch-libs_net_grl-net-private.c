$NetBSD: patch-libs_net_grl-net-private.c,v 1.1 2013/09/01 07:49:53 richard Exp $

avoid -Werror=format problems

--- libs/net/grl-net-private.c.orig	2013-05-01 09:51:51.000000000 +0000
+++ libs/net/grl-net-private.c
@@ -153,7 +153,7 @@ dump_data (SoupURI *uri,
 
   /* Append record about the just written file to "grl-net-mock-data-%PID.ini"
    * in the capture directory. */
-  char *filename = g_strdup_printf ("grl-net-mock-data-%u.ini", getpid());
+  char *filename = g_strdup_printf ("grl-net-mock-data-%u.ini", (unsigned int)getpid());
   path = g_build_filename (capture_dir, filename, NULL);
   g_free (filename);
 
