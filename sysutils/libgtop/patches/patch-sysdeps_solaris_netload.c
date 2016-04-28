$NetBSD: patch-sysdeps_solaris_netload.c,v 1.1 2016/04/28 22:18:58 jperkin Exp $

Find correct network interfaces.

--- sysdeps/solaris/netload.c.orig	2011-06-01 15:40:47.000000000 +0000
+++ sysdeps/solaris/netload.c
@@ -105,7 +105,7 @@ solaris_stats(glibtop *server,
 	/*
 	 *  chop off the trailing interface
 	 */
-	module = strdup( name );
+	module = strdup( "link" );
 	ptr = module + strlen( module ) - 1;
 	while( (ptr > module) && isdigit( (int) *ptr ) ) {
 		*ptr = '\0';
