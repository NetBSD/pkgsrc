$NetBSD: patch-src_framework_mlt__properties.c,v 1.1 2013/06/26 21:59:10 joerg Exp $

--- src/framework/mlt_properties.c.orig	2013-06-26 21:38:59.000000000 +0000
+++ src/framework/mlt_properties.c
@@ -138,7 +138,7 @@ int mlt_properties_set_lcnumeric( mlt_pr
 	{
 		property_list *list = self->local;
 
-#if defined(__linux__) || defined(__DARWIN__)
+#if defined(__linux__) || defined(__DARWIN__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
 		if ( list->locale )
 			freelocale( list->locale );
 		list->locale = newlocale( LC_NUMERIC_MASK, locale, NULL );
@@ -1332,7 +1332,7 @@ void mlt_properties_close( mlt_propertie
 				free( list->name[ index ] );
 			}
 
-#if defined(__linux__) || defined(__DARWIN__)
+#if defined(__linux__) || defined(__DARWIN__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
 			// Cleanup locale
 			if ( list->locale )
 				freelocale( list->locale );
