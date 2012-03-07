$NetBSD: patch-dist_include_prop_prop__string.h,v 1.1 2012/03/07 11:39:40 hans Exp $

--- dist/include/prop/prop_string.h.orig	2008-02-29 19:25:58.000000000 +0100
+++ dist/include/prop/prop_string.h	2012-03-02 20:18:31.107164376 +0100
@@ -43,6 +43,8 @@
 
 typedef struct _prop_string *prop_string_t;
 
+#include <sys/cdefs.h>
+
 __BEGIN_DECLS
 prop_string_t	prop_string_create(void);
 prop_string_t	prop_string_create_cstring(const char *);
