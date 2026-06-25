$NetBSD: patch-src_polkitbackend_polkitbackendduktapeauthority.c,v 1.4 2026/06/25 10:29:54 wiz Exp $

Avoid %m usage in printf.
https://github.com/polkit-org/polkit/pull/624

--- src/polkitbackend/polkitbackendduktapeauthority.c.orig	2026-06-25 10:19:41.076186959 +0000
+++ src/polkitbackend/polkitbackendduktapeauthority.c
@@ -436,7 +436,7 @@ if (passwd == NULL)
 if (passwd == NULL)
   {
     user_name = g_strdup_printf ("%d", (gint) uid);
-    g_warning ("Error looking up info for uid %d: %m", (gint) uid);
+    g_warning ("Error looking up info for uid %d", (gint) uid);
   }
 else
   {
@@ -474,7 +474,7 @@ else
                             gids,
                             &num_gids) < 0)
             {
-              g_warning ("Error looking up groups for uid %d: %m", (gint) uid);
+              g_warning ("Error looking up groups for uid %d: %s", (gint) uid, g_strerror(errno));
             }
           else
             {
