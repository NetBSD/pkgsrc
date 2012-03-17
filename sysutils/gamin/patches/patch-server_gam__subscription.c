$NetBSD: patch-server_gam__subscription.c,v 1.1 2012/03/17 02:19:08 wiz Exp $

G_CONST_RETURN has been obsoleted.

--- server/gam_subscription.c.orig	2007-07-04 13:36:49.000000000 +0000
+++ server/gam_subscription.c
@@ -141,7 +141,7 @@ gam_subscription_pathlen(GamSubscription
  * @param sub the GamSubscription
  * @returns The path being monitored.  It should not be freed.
  */
-G_CONST_RETURN char *
+const char *
 gam_subscription_get_path(GamSubscription * sub)
 {
     if (sub == NULL)
