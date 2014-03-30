$NetBSD: patch-src_framework_mlt__property.c,v 1.2 2014/03/30 19:42:53 abs Exp $

Add conditional section for __NetBSD__

--- src/framework/mlt_property.c.orig	2013-06-03 03:34:35.000000000 +0000
+++ src/framework/mlt_property.c
@@ -280,7 +280,7 @@ static int time_clock_to_frames( const c
 	s = copy;
 	pos = strrchr( s, ':' );
 	if ( pos ) {
-#if defined(__GLIBC__) || defined(__DARWIN__)
+#if defined(__GLIBC__) || defined(__DARWIN__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
 		if ( locale )
 			seconds = strtod_l( pos + 1, NULL, locale );
 		else
@@ -298,7 +298,7 @@ static int time_clock_to_frames( const c
 		}
 	}
 	else {
-#if defined(__GLIBC__) || defined(__DARWIN__)
+#if defined(__GLIBC__) || defined(__DARWIN__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
 		if ( locale )
 			seconds = strtod_l( s, NULL, locale );
 		else
@@ -459,7 +459,7 @@ static double mlt_property_atof( const c
 	{
 		char *end = NULL;
 		double result;
-#if defined(__GLIBC__) || defined(__DARWIN__)
+#if defined(__GLIBC__) || defined(__DARWIN__) || (defined(__NetBSD__) && defined(LC_C_LOCALE))
 		if ( locale )
 			result = strtod_l( value, &end, locale );
         else
