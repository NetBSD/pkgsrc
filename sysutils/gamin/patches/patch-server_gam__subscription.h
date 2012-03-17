$NetBSD: patch-server_gam__subscription.h,v 1.1 2012/03/17 02:19:08 wiz Exp $

G_CONST_RETURN has been obsoleted.

--- server/gam_subscription.h.orig	2007-07-04 13:36:49.000000000 +0000
+++ server/gam_subscription.h
@@ -21,7 +21,7 @@ int                  gam_subscription_pa
 
 int                  gam_subscription_get_reqno    (GamSubscription *sub);
 
-G_CONST_RETURN char *gam_subscription_get_path     (GamSubscription *sub);
+const char *gam_subscription_get_path     (GamSubscription *sub);
 
 GamListener         *gam_subscription_get_listener (GamSubscription *sub);
 
