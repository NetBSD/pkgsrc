$NetBSD: patch-config-scripts_cups-gssapi.m4,v 1.1 2011/10/13 13:05:57 hans Exp $

--- config-scripts/cups-gssapi.m4.orig	2009-05-19 00:03:04.000000000 +0200
+++ config-scripts/cups-gssapi.m4	2011-09-20 18:57:15.406259164 +0200
@@ -29,14 +29,6 @@ if test x$enable_gssapi != xno; then
 				# Mac OS X weak-links to the Kerberos framework...
 				LIBGSSAPI="-weak_framework Kerberos"
 				;;
-			SunOS*)
-				# Solaris has a non-standard krb5-config, don't use it!
-				AC_CHECK_LIB(gss, gss_display_status,
-					AC_DEFINE(HAVE_GSSAPI, 1, [Whether GSSAPI is available])
-					CFLAGS="`$KRB5CONFIG --cflags` $CFLAGS"		
-					CPPFLAGS="`$KRB5CONFIG --cflags` $CPPFLAGS"		
-					LIBGSSAPI="-lgss `$KRB5CONFIG --libs`")
-				;;
 			*)
 				# Other platforms just ask for GSSAPI
 				CFLAGS="`$KRB5CONFIG --cflags gssapi` $CFLAGS"		
