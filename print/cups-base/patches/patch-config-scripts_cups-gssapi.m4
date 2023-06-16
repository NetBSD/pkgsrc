$NetBSD: patch-config-scripts_cups-gssapi.m4,v 1.4 2023/06/16 21:12:11 wiz Exp $

builtin krb5-config in platforms such as solaris do not support
the gssapi option, and need an explicit -lgss

--- config-scripts/cups-gssapi.m4.orig	2023-06-06 12:55:36.000000000 +0000
+++ config-scripts/cups-gssapi.m4
@@ -30,31 +30,22 @@ AS_IF([test x$enable_gssapi = xyes], [
 	], [
 	    AC_MSG_RESULT([no])
 	])
-    ], [sunos* | solaris*], [
-	# Solaris has a non-standard krb5-config, don't use it!
-	SAVELIBS="$LIBS"
-	AC_CHECK_LIB([gss], [gss_display_status], [
-	    AC_DEFINE([HAVE_GSSAPI], [1], [Is GSSAPI available?])
-	    AS_IF([test "x$KRB5CONFIG" != x], [
-		CFLAGS="$($KRB5CONFIG --cflags) $CFLAGS"
-		CPPFLAGS="$($KRB5CONFIG --cflags) $CPPFLAGS"
-		LIBGSSAPI="-lgss $($KRB5CONFIG --libs)"
-	    ], [
-	        LIBGSSAPI="-lgss"
-	    ])
-	], [
-	    AC_MSG_ERROR([--enable-gssapi specified but GSSAPI library cannot be found.])
-	])
-	LIBS="$SAVELIBS"
     ], [*], [
 	# Other platforms just ask for GSSAPI
 	AS_IF([test "x$KRB5CONFIG" = x], [
 	    AC_MSG_ERROR([--enable-gssapi specified but krb5-config cannot be found.])
 	], [
 	    AC_DEFINE([HAVE_GSSAPI], [1], [Is GSSAPI available?])
-	    CFLAGS="$($KRB5CONFIG --cflags gssapi) $CFLAGS"
-	    CPPFLAGS="$($KRB5CONFIG --cflags gssapi) $CPPFLAGS"
-	    LIBGSSAPI="$($KRB5CONFIG --libs gssapi)"
+            # make sure krb5-config supports gssapi option
+            AS_IF([$KRB5CONFIG --cflags gssapi 2>&1 | grep "Unknown option" > /dev/null], [
+                CFLAGS="$($KRB5CONFIG --cflags) $CFLAGS"
+                CPPFLAGS="$($KRB5CONFIG --cflags) $CPPFLAGS"
+                LIBGSSAPI="-lgss $($KRB5CONFIG --libs)"
+            ], [
+                CFLAGS="$($KRB5CONFIG --cflags gssapi) $CFLAGS"
+                CPPFLAGS="$($KRB5CONFIG --cflags gssapi) $CPPFLAGS"
+                LIBGSSAPI="$($KRB5CONFIG --libs gssapi)"
+            ])
 	])
     ])
 
