$NetBSD: patch-server_gam__node.c,v 1.1 2012/03/17 02:19:08 wiz Exp $

G_CONST_RETURN has been obsoleted.

--- server/gam_node.c.orig	2007-07-04 13:36:49.000000000 +0000
+++ server/gam_node.c
@@ -122,7 +122,7 @@ gam_node_set_is_dir(GamNode * node, gboo
  * it has finished with the string.  If it must keep it longer, it
  * should makes its own copy.  The returned string must not be freed.
  */
-G_CONST_RETURN char *
+const char *
 gam_node_get_path(GamNode * node)
 {
     g_assert(node);
