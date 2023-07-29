$NetBSD: patch-io-webp.c,v 1.1 2023/07/29 18:08:38 tsutsui Exp $

- update_func() shall be called for proper signal delivery
  https://github.com/aruiz/webp-pixbuf-loader/pull/73

--- io-webp.c.orig	2023-03-30 00:29:21.000000000 +0000
+++ io-webp.c
@@ -189,6 +189,8 @@ stop_load (gpointer data, GError **error
         {
           if (context->prepare_func)
             context->prepare_func (pb, NULL, context->user_data);
+          if (context->update_func)
+            context->update_func (pb, 0, 0, context->width, context->height, context->user_data);
 
           g_clear_object (&pb);
 
