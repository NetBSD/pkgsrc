$NetBSD: patch-include_xine_post.h,v 1.3 2020/04/02 15:52:46 nia Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

--- include/xine/post.h.orig	2019-12-13 20:47:50.000000000 +0000
+++ include/xine/post.h
@@ -436,7 +436,7 @@ static xine_post_api_parameter_t temp_p[
 #include <stddef.h>
 #endif
 
-#define PARAM_ITEM( param_type, var, enumv, min, max, readonly, descr ) \
+#define PARAM_ITEM( param_t, param_type, var, enumv, min, max, readonly, descr ) \
 { param_type, #var, sizeof(((temp_t*)0)->var),                        \
   offsetof(temp_t, var), enumv, min, max, readonly, descr },
 
