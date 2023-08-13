$NetBSD: patch-io-webp.c,v 1.3 2023/08/13 00:34:47 tsutsui Exp $

- update_func() shall be called for proper signal delivery
  https://github.com/aruiz/webp-pixbuf-loader/pull/73

--- io-webp.c.orig	2023-03-30 00:29:21.000000000 +0000
+++ io-webp.c
@@ -143,6 +143,8 @@ stop_load (gpointer data, GError **error
         {
           if (context->prepare_func)
             context->prepare_func (pb, GDK_PIXBUF_ANIMATION (anim), context->user_data);
+          if (context->update_func)
+            context->update_func (pb, 0, 0, context->width, context->height, context->user_data);
           ret = TRUE;
         }
 
@@ -174,6 +176,9 @@ stop_load (gpointer data, GError **error
           return FALSE;
         }
 
+      if (context->prepare_func)
+        context->prepare_func (pb, NULL, context->user_data);
+
       if (icc_data)
         {
           gdk_pixbuf_set_option (pb, "icc-profile", icc_data);
@@ -187,10 +192,8 @@ stop_load (gpointer data, GError **error
                                          context->buffer->len, &config);
       if (status == VP8_STATUS_OK)
         {
-          if (context->prepare_func)
-            context->prepare_func (pb, NULL, context->user_data);
-
-          g_clear_object (&pb);
+          if (context->update_func)
+            context->update_func (pb, 0, 0, context->width, context->height, context->user_data);
 
           ret = TRUE;
         }
@@ -198,6 +201,8 @@ stop_load (gpointer data, GError **error
         g_set_error (error, GDK_PIXBUF_ERROR, GDK_PIXBUF_ERROR_FAILED,
                           "WebP decoder failed with VP8 status code: %d", status);
       }
+
+      g_clear_object (&pb);
     }
 
   if (context->buffer)
