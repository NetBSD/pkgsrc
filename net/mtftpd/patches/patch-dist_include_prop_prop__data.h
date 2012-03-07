$NetBSD: patch-dist_include_prop_prop__data.h,v 1.1 2012/03/07 11:39:40 hans Exp $

--- dist/include/prop/prop_data.h.orig	2008-02-29 19:25:58.000000000 +0100
+++ dist/include/prop/prop_data.h	2012-03-02 20:14:27.311989501 +0100
@@ -43,6 +43,8 @@
 
 typedef struct _prop_data *prop_data_t;
 
+#include <sys/cdefs.h>
+
 __BEGIN_DECLS
 prop_data_t	prop_data_create_data(const void *, size_t);
 prop_data_t	prop_data_create_data_nocopy(const void *, size_t);
