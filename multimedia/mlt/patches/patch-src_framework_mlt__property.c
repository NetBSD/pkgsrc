$NetBSD: patch-src_framework_mlt__property.c,v 1.1 2013/06/26 21:59:10 joerg Exp $

--- src/framework/mlt_property.c.orig	2013-06-26 21:38:25.000000000 +0000
+++ src/framework/mlt_property.c
@@ -282,7 +282,7 @@ static int time_clock_to_frames( const c
 	s = copy;
 	pos = strrchr( s, ':' );
 	if ( pos ) {
-#if defined(__GLIBC__) || defined(__DARWIN__)
+#if defined(__GLIBC__) || defined(__DARWIN__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
 		if ( locale )
 			seconds = strtod_l( pos + 1, NULL, locale );
 		else
@@ -300,7 +300,7 @@ static int time_clock_to_frames( const c
 		}
 	}
 	else {
-#if defined(__GLIBC__) || defined(__DARWIN__)
+#if defined(__GLIBC__) || defined(__DARWIN__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
 		if ( locale )
 			seconds = strtod_l( s, NULL, locale );
 		else
@@ -455,7 +455,7 @@ static double mlt_property_atof( const c
 	}
 	else
 	{
-#if defined(__GLIBC__) || defined(__DARWIN__)
+#if defined(__GLIBC__) || defined(__DARWIN__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
 		if ( locale )
 			return strtod_l( value, NULL, locale );
 #endif
