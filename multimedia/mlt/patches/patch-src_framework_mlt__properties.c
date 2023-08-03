$NetBSD: patch-src_framework_mlt__properties.c,v 1.4 2023/08/03 02:03:16 markd Exp $

Add conditional section for __NetBSD__

--- src/framework/mlt_properties.c.orig	2023-07-28 18:06:26.000000000 +0000
+++ src/framework/mlt_properties.c
@@ -144,7 +144,7 @@ int mlt_properties_set_lcnumeric(mlt_pro
     if (self && locale) {
         property_list *list = self->local;
 
-#if defined(__GLIBC__) || defined(__APPLE__)
+#if defined(__GLIBC__) || defined(__APPLE__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
         if (list->locale)
             freelocale(list->locale);
         list->locale = newlocale(LC_NUMERIC_MASK, locale, NULL);
@@ -1509,7 +1509,7 @@ void mlt_properties_close(mlt_properties
                 free(list->name[index]);
             }
 
-#if defined(__GLIBC__) || defined(__APPLE__)
+#if defined(__GLIBC__) || defined(__APPLE__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
             // Cleanup locale
             if (list->locale)
                 freelocale(list->locale);
