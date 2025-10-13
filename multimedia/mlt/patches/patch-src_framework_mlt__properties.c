$NetBSD: patch-src_framework_mlt__properties.c,v 1.5 2025/10/13 02:22:16 mrg Exp $

Avoid the strtod_l() etc code on NetBSD as well, it is attempts
to convert between "char *" and "locale_t" directly.


--- src/framework/mlt_properties.c.orig	2025-05-07 15:48:51.000000000 -0700
+++ src/framework/mlt_properties.c	2025-10-12 14:16:04.796329616 -0700
@@ -759,7 +759,7 @@ int mlt_properties_set(mlt_properties se
 
             // Determine the value
             if (isdigit(id[0])) {
-#if defined(__GLIBC__) || defined(__APPLE__) || HAVE_STRTOD_L && !defined(__OpenBSD__)
+#if defined(__GLIBC__) || defined(__APPLE__) || HAVE_STRTOD_L && !defined(__OpenBSD__) && !defined(__NetBSD__)
                 property_list *list = self->local;
                 if (list->locale)
                     current = strtod_l(id, NULL, list->locale);
