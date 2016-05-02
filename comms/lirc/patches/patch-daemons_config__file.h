$NetBSD: patch-daemons_config__file.h,v 1.1 2016/05/02 02:32:14 dholland Exp $

Patch up gcc inline mess.

--- daemons/config_file.h~	2011-03-25 22:28:18.000000000 +0000
+++ daemons/config_file.h
@@ -67,7 +67,6 @@ struct void_array {
 
 void **init_void_array(struct void_array *ar, size_t chunk_size, size_t item_size);
 int add_void_array(struct void_array *ar, void *data);
-inline void *get_void_array(struct void_array *ar);
 
 /* some safer functions */
 void *s_malloc(size_t size);
