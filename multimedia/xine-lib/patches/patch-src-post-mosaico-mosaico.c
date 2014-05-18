$NetBSD: patch-src-post-mosaico-mosaico.c,v 1.2 2014/05/18 15:38:18 wiz Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

--- src/post/mosaico/mosaico.c.orig	2011-08-30 13:13:38.000000000 +0000
+++ src/post/mosaico/mosaico.c
@@ -55,15 +55,20 @@ typedef struct mosaico_parameters_s {
 } mosaico_parameters_t;
 
 START_PARAM_DESCR(mosaico_parameters_t)
-PARAM_ITEM(POST_PARAM_TYPE_INT, pip_num, NULL, 1, INT_MAX, 1,
+PARAM_ITEM(mosaico_parameters_t, 
+  POST_PARAM_TYPE_INT, pip_num, NULL, 1, INT_MAX, 1,
   "which picture slots settings are being edited")
-PARAM_ITEM(POST_PARAM_TYPE_INT, x, NULL, 0, INT_MAX, 50,
+PARAM_ITEM(mosaico_parameters_t, 
+  POST_PARAM_TYPE_INT, x, NULL, 0, INT_MAX, 50,
   "x coordinate of the pasted picture")
-PARAM_ITEM(POST_PARAM_TYPE_INT, y, NULL, 0, INT_MAX, 50,
+PARAM_ITEM(mosaico_parameters_t, 
+  POST_PARAM_TYPE_INT, y, NULL, 0, INT_MAX, 50,
   "y coordinate of the pasted picture")
-PARAM_ITEM(POST_PARAM_TYPE_INT, w, NULL, 0, INT_MAX, 150,
+PARAM_ITEM(mosaico_parameters_t, 
+  POST_PARAM_TYPE_INT, w, NULL, 0, INT_MAX, 150,
   "width of the pasted picture")
-PARAM_ITEM(POST_PARAM_TYPE_INT, h, NULL, 0, INT_MAX, 150,
+PARAM_ITEM(mosaico_parameters_t, 
+  POST_PARAM_TYPE_INT, h, NULL, 0, INT_MAX, 150,
   "height of the pasted picture")
 END_PARAM_DESCR(mosaico_param_descr)
 
