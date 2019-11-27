$NetBSD: patch-src_framework_mlt__properties.c,v 1.3 2019/11/27 21:32:09 markd Exp $

Add conditional section for __NetBSD__

--- src/framework/mlt_properties.c.orig	2019-11-12 01:44:42.000000000 +0000
+++ src/framework/mlt_properties.c
@@ -141,7 +141,7 @@ int mlt_properties_set_lcnumeric( mlt_pr
 	{
 		property_list *list = self->local;
 
-#if defined(__GLIBC__) || defined(__APPLE__)
+#if defined(__GLIBC__) || defined(__APPLE__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
 		if ( list->locale )
 			freelocale( list->locale );
 		list->locale = newlocale( LC_NUMERIC_MASK, locale, NULL );
@@ -1425,7 +1425,7 @@ void mlt_properties_close( mlt_propertie
 				free( list->name[ index ] );
 			}
 
-#if defined(__GLIBC__) || defined(__APPLE__)
+#if defined(__GLIBC__) || defined(__APPLE__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
 			// Cleanup locale
 			if ( list->locale )
 				freelocale( list->locale );
