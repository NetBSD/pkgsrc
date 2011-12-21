$NetBSD: patch-cfparse.y,v 1.1 2011/12/21 11:58:41 wiz Exp $

Fix build with gcc-4.5.

--- cfparse.y.orig	2003-10-21 08:15:45.000000000 +0000
+++ cfparse.y
@@ -1232,7 +1232,7 @@ cf_post_config()
 
 /* initialize all the temporary variables */
 void
-cf_init(s, d)
+cf_init(int s, int d)
 {
 	struct uvif *v;
 	mifi_t vifi;
