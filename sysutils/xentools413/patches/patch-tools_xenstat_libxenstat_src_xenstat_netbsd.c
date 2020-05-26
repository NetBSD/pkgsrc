$NetBSD: patch-tools_xenstat_libxenstat_src_xenstat_netbsd.c,v 1.1 2020/05/26 11:12:11 bouyer Exp $

Fix unused functions/variables error

--- tools/xenstat/libxenstat/src/xenstat_netbsd.c.orig	2020-05-08 20:37:14.116639155 +0200
+++ tools/xenstat/libxenstat/src/xenstat_netbsd.c	2020-05-08 20:37:51.740635933 +0200
@@ -55,11 +55,6 @@
 }
 
 /* Expected format of /proc/net/dev */
-static const char PROCNETDEV_HEADER[] =
-    "Inter-|   Receive                                                |"
-    "  Transmit\n"
-    " face |bytes    packets errs drop fifo frame compressed multicast|"
-    "bytes    packets errs drop fifo colls carrier compressed\n";
 
 /* Collect information about networks */
 int xenstat_collect_networks(xenstat_node * node)
@@ -76,12 +71,6 @@
 		fclose(priv->procnetdev);
 }
 
-static int read_attributes_vbd(const char *vbd_directory, const char *what, char *ret, int cap)
-{
-	/* XXX implement */
-	return 0;
-}
-
 /* Collect information about VBDs */
 int xenstat_collect_vbds(xenstat_node * node)
 {
