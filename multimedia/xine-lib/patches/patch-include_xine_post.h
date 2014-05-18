$NetBSD: patch-include_xine_post.h,v 1.2 2014/05/18 15:38:18 wiz Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

--- include/xine/post.h.orig	2014-02-26 15:49:10.000000000 +0000
+++ include/xine/post.h
@@ -400,9 +400,9 @@ static xine_post_api_parameter_t temp_p[
 #include <stddef.h>
 #endif
 
-#define PARAM_ITEM( param_type, var, enumv, min, max, readonly, descr ) \
-{ param_type, #var, sizeof(temp_s.var), \
-  offsetof(temp_t, var), enumv, min, max, readonly, descr },
+#define PARAM_ITEM( param_t, param_type, var, enumv, min, max, readonly, descr ) \
+{ param_type, #var, sizeof(temp_s.var), offsetof(param_t, var), \
+  enumv, min, max, readonly, descr },
 
 #define END_PARAM_DESCR( name ) \
   { POST_PARAM_TYPE_LAST, NULL, 0, 0, NULL, 0, 0, 1, NULL } \
