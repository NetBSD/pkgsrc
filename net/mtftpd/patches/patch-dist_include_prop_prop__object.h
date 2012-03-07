$NetBSD: patch-dist_include_prop_prop__object.h,v 1.1 2012/03/07 11:39:40 hans Exp $

--- dist/include/prop/prop_object.h.orig	2008-02-29 19:25:58.000000000 +0100
+++ dist/include/prop/prop_object.h	2012-03-02 20:14:02.076547621 +0100
@@ -59,6 +59,8 @@ typedef enum {
 	PROP_TYPE_DICT_KEYSYM	=	0x646b6579	/* 'dkey' */
 } prop_type_t;
 
+#include <sys/cdefs.h>
+
 __BEGIN_DECLS
 void		prop_object_retain(prop_object_t);
 void		prop_object_release(prop_object_t);
