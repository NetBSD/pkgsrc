$NetBSD: patch-src_layers.h,v 1.1 2012/11/19 03:06:04 joerg Exp $

--- src/layers.h.orig	2012-11-19 00:55:12.000000000 +0000
+++ src/layers.h
@@ -39,8 +39,8 @@ typedef enum layer
   LAYER_APPLICATION
 } layer_t;
 
-inline void    set_layer(layer_t);
-inline layer_t get_layer(void);
-inline int     check_layer(void);
+void    set_layer(layer_t);
+layer_t get_layer(void);
+int     check_layer(void);
 
 #endif
