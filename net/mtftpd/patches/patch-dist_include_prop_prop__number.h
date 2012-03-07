$NetBSD: patch-dist_include_prop_prop__number.h,v 1.1 2012/03/07 11:39:40 hans Exp $

--- dist/include/prop/prop_number.h.orig	2008-02-29 19:25:58.000000000 +0100
+++ dist/include/prop/prop_number.h	2012-03-02 20:17:44.973100443 +0100
@@ -46,6 +46,8 @@
 
 typedef struct _prop_number *prop_number_t;
 
+#include <sys/cdefs.h>
+
 __BEGIN_DECLS
 prop_number_t	prop_number_create_integer(int64_t);
 prop_number_t	prop_number_create_unsigned_integer(uint64_t);
