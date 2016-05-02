$NetBSD: patch-daemons_config__file.c,v 1.1 2016/05/02 02:32:14 dholland Exp $

Patch up gcc inline mess.

--- daemons/config_file.c~	2011-03-25 22:28:18.000000000 +0000
+++ daemons/config_file.c
@@ -77,7 +77,7 @@ int add_void_array(struct void_array *ar
 	return (1);
 }
 
-inline void *get_void_array(struct void_array *ar)
+static inline void *get_void_array(struct void_array *ar)
 {
 	return (ar->ptr);
 }
