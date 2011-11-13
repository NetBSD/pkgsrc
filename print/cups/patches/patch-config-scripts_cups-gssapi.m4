$NetBSD: patch-config-scripts_cups-gssapi.m4,v 1.2 2011/11/13 21:49:17 sbd Exp $

--- config-scripts/cups-gssapi.m4.orig	2011-05-12 05:21:56.000000000 +0000
+++ config-scripts/cups-gssapi.m4
@@ -36,14 +36,6 @@ if test x$enable_gssapi != xno; then
 					AC_MSG_RESULT(no)
 				fi
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
