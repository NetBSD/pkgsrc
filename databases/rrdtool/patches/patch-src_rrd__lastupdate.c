$NetBSD: patch-src_rrd__lastupdate.c,v 1.1 2017/07/27 18:31:20 adam Exp $

--- src/rrd_lastupdate.c.orig	2012-01-24 10:08:48.000000000 +0000
+++ src/rrd_lastupdate.c
@@ -75,7 +75,7 @@ int rrd_lastupdate (int argc, char **arg
         printf(" %s", ds_names[i]);
     printf ("\n\n");
 
-    printf ("%10lu:", last_update);
+    printf ("%10llu:", (unsigned long long)last_update);
     for (i = 0; i < ds_count; i++) {
         printf(" %s", last_ds[i]);
         free(last_ds[i]);
