$NetBSD: patch-dist_include_prop_prop__array.h,v 1.1 2012/03/07 11:39:40 hans Exp $

--- dist/include/prop/prop_array.h.orig	2008-02-29 19:25:58.000000000 +0100
+++ dist/include/prop/prop_array.h	2012-03-02 20:15:04.196726515 +0100
@@ -43,6 +43,8 @@
 
 typedef struct _prop_array *prop_array_t;
 
+#include <sys/cdefs.h>
+
 __BEGIN_DECLS
 prop_array_t	prop_array_create(void);
 prop_array_t	prop_array_create_with_capacity(unsigned int);
