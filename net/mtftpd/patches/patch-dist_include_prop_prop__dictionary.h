$NetBSD: patch-dist_include_prop_prop__dictionary.h,v 1.1 2012/03/07 11:39:40 hans Exp $

--- dist/include/prop/prop_dictionary.h.orig	2008-02-29 19:25:58.000000000 +0100
+++ dist/include/prop/prop_dictionary.h	2012-03-02 20:16:51.097919841 +0100
@@ -44,6 +44,8 @@
 typedef struct _prop_dictionary *prop_dictionary_t;
 typedef struct _prop_dictionary_keysym *prop_dictionary_keysym_t;
 
+#include <sys/cdefs.h>
+
 __BEGIN_DECLS
 prop_dictionary_t prop_dictionary_create(void);
 prop_dictionary_t prop_dictionary_create_with_capacity(unsigned int);
