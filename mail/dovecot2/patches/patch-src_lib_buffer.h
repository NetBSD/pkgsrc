$NetBSD: patch-src_lib_buffer.h,v 1.1 2015/09/23 11:58:56 joerg Exp $

--- src/lib/buffer.h.orig	2015-09-22 21:27:02.000000000 +0000
+++ src/lib/buffer.h
@@ -20,7 +20,7 @@ void buffer_create_from_const_data(buffe
 				   const void *data, size_t size);
 #if defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__) > 401
 #define buffer_create_from_data(b,d,s) ({					\
-	(void)COMPILE_ERROR_IF_TRUE(__builtin_object_size((d),3) < ((s)?(s):1)); \
+	(void)COMPILE_ERROR_IF_TRUE(__builtin_object_size((d),3) != 0 && __builtin_object_size((d),3) < ((s)?(s):1)); \
 	buffer_create_from_data((b), (d), (s)); })
 #define buffer_create_from_const_data(b,d,s) ({					\
 	(void)COMPILE_ERROR_IF_TRUE(__builtin_object_size((d),3) < ((s)?(s):1)); \
