$NetBSD: patch-gnucash_gnome-utils_gnc-menu-extensions.c,v 1.2 2019/01/11 12:01:11 wiz Exp $

Fix build with clang
error: array subscript is of type 'char'
https://bugs.gnucash.org/show_bug.cgi?id=797039

--- gnucash/gnome-utils/gnc-menu-extensions.c.orig	2018-12-25 22:43:08.000000000 +0000
+++ gnucash/gnome-utils/gnc-menu-extensions.c
@@ -221,7 +221,7 @@ gnc_ext_gen_action_name (const gchar *na
     // 'Mum & ble12' => 'Mumble___ble12'
     for ( extChar = name; *extChar != '\0'; extChar++ )
     {
-        if ( ! isalnum( *extChar ) )
+        if ( ! isalnum((unsigned char) *extChar ) )
             g_string_append_c( actionName, '_' );
         g_string_append_c( actionName, *extChar );
     }
