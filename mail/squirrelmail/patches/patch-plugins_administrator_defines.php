$NetBSD: patch-plugins_administrator_defines.php,v 1.1 2016/09/27 12:11:11 manu Exp $

Fix syntax error, form Jean-Jacques Puig 

--- plugins/administrator/defines.php.orig
+++ plugins/administrator/defines.php
@@ -243,6 +243,7 @@
                  '$edit_identity' => array( 'name' => _("Allow editing of identities"),
                                             'type' => SMOPT_TYPE_BOOLEAN ),
                  '$edit_name' => array( 'name' => _("Allow editing of full name"),
+                                            'type' => SMOPT_TYPE_BOOLEAN ),
                  '$edit_reply_to' => array( 'name' => _("Allow editing of reply-to address"),
                                         'type' => SMOPT_TYPE_BOOLEAN ),
                  '$hide_auth_header' => array( 'name' => _("Remove username from headers"),
