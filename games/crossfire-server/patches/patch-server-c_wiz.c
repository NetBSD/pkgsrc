$NetBSD: patch-server-c_wiz.c,v 1.1 2011/08/20 15:32:48 joerg Exp $

--- server/c_wiz.c.orig	2011-08-20 14:21:07.000000000 +0000
+++ server/c_wiz.c
@@ -2134,17 +2134,17 @@ int command_follow(object* op, char* par
             draw_ext_info_format(NDI_UNIQUE, 0, op, MSG_TYPE_ADMIN, MSG_TYPE_ADMIN_DM, "You stop following %s.", NULL, op->contr->followed_player);
             FREE_AND_CLEAR_STR(op->contr->followed_player);
         }
-        return;
+        return 1;
     }
 
     other = find_player_partial_name(params);
     if (!other) {
         draw_ext_info(NDI_UNIQUE, 0, op, MSG_TYPE_ADMIN, MSG_TYPE_ADMIN_DM, "No such player or ambiguous name.", NULL);
-        return;
+        return 1;
     }
     if (other == op->contr) {
         draw_ext_info(NDI_UNIQUE, 0, op, MSG_TYPE_ADMIN, MSG_TYPE_ADMIN_DM, "You can't follow yourself.", NULL);
-        return;
+        return 1;
     }
 
     if (op->contr->followed_player)
@@ -2152,4 +2152,5 @@ int command_follow(object* op, char* par
 
     op->contr->followed_player = add_string(other->ob->name);
     draw_ext_info_format(NDI_UNIQUE, 0, op, MSG_TYPE_ADMIN, MSG_TYPE_ADMIN_DM, "Following %s.", NULL, op->contr->followed_player);
+    return 1;
 }
