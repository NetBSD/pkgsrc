$NetBSD: patch-app_layers__dialog.c,v 1.2 2018/12/31 13:11:12 ryoon Exp $

--- app/layers_dialog.c.orig	2007-11-09 15:24:27.000000000 +0000
+++ app/layers_dialog.c
@@ -2773,7 +2773,7 @@ layer_widget_preview_redraw (LayerWidget
 # ifdef DEBUG
     printf("%s:%d %s() wrong data or widget\n", __FILE__,__LINE__,__func__);
 # endif
-    return FALSE;
+    return;
   }
 
 
