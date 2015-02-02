$NetBSD: patch-src_cjson.c,v 1.1 2015/02/02 12:25:20 he Exp $

Avoid compiler warning for using signed chars with tolower().

--- src/cjson.c.orig	2015-01-09 17:44:11.000000000 +0000
+++ src/cjson.c
@@ -56,7 +56,7 @@ static int cJSON_strcasecmp( const char 
 		return ( s1 == s2 ) ? 0 : 1;
 	if ( ! s2 )
 		return 1;
-	for ( ; tolower(*s1) == tolower(*s2); ++s1, ++s2)
+	for ( ; tolower((u_char)*s1) == tolower((u_char)*s2); ++s1, ++s2)
 		if( *s1 == 0 )
 			return 0;
 	return tolower(*(const unsigned char *)s1) - tolower(*(const unsigned char *)s2);
