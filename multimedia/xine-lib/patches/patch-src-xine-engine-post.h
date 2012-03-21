$NetBSD: patch-src-xine-engine-post.h,v 1.2 2012/03/21 16:37:15 drochner Exp $

--- include/xine/post.h.orig	2010-03-09 22:17:05.000000000 +0000
+++ include/xine/post.h
@@ -370,14 +370,15 @@ do {                                    
 
 
 /* macros to create parameter descriptors */
+#include <stddef.h>
 
 #define START_PARAM_DESCR( param_t ) \
 static param_t temp_s; \
 static xine_post_api_parameter_t temp_p[] = {
 
-#define PARAM_ITEM( param_type, var, enumv, min, max, readonly, descr ) \
-{ param_type, #var, sizeof(temp_s.var), \
-  (char*)&temp_s.var-(char*)&temp_s, enumv, min, max, readonly, descr },
+#define PARAM_ITEM( param_t, param_type, var, enumv, min, max, readonly, descr ) \
+{ param_type, #var, sizeof(temp_s.var), offsetof(param_t, var), \
+  enumv, min, max, readonly, descr },
 
 #define END_PARAM_DESCR( name ) \
   { POST_PARAM_TYPE_LAST, NULL, 0, 0, NULL, 0, 0, 1, NULL } \
