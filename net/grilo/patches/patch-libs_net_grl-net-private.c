$NetBSD: patch-libs_net_grl-net-private.c,v 1.2 2014/02/05 17:36:38 drochner Exp $

avoid -Werror=format problems

--- libs/net/grl-net-wc.c.orig	2013-09-13 16:04:54.000000000 +0000
+++ libs/net/grl-net-wc.c
@@ -546,7 +546,7 @@ dump_data (SoupURI *uri,
 
   /* Append record about the just written file to "grl-net-mock-data-%PID.ini"
    * in the capture directory. */
-  char *filename = g_strdup_printf ("grl-net-mock-data-%u.ini", getpid());
+  char *filename = g_strdup_printf ("grl-net-mock-data-%u.ini", (unsigned int)getpid());
   path = g_build_filename (capture_dir, filename, NULL);
   g_free (filename);
 
