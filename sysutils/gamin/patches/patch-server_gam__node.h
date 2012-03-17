$NetBSD: patch-server_gam__node.h,v 1.1 2012/03/17 02:19:08 wiz Exp $

G_CONST_RETURN has been obsoleted.

--- server/gam_node.h.orig	2007-07-04 13:36:49.000000000 +0000
+++ server/gam_node.h
@@ -58,7 +58,7 @@ gboolean              gam_node_is_dir   
 void                  gam_node_set_is_dir          (GamNode         *node,
 						   gboolean        is_dir);
 	
-G_CONST_RETURN char  *gam_node_get_path            (GamNode         *node);
+const char  *gam_node_get_path            (GamNode         *node);
 
 GList                *gam_node_get_subscriptions   (GamNode         *node);
 
