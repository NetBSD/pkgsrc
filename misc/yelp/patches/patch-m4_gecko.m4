$NetBSD: patch-m4_gecko.m4,v 1.1 2011/06/26 12:46:06 obache Exp $

* xulrunner-2 support.

--- m4/gecko.m4.orig	2010-08-03 19:41:59.000000000 +0000
+++ m4/gecko.m4
@@ -212,25 +212,6 @@ AC_LANG_PUSH([C++])
 _SAVE_CPPFLAGS="$CPPFLAGS"
 CPPFLAGS="$CPPFLAGS $_GECKO_EXTRA_CPPFLAGS $_GECKO_CFLAGS"
 
-AC_MSG_CHECKING([[whether we have a gtk 2 gecko build]])
-AC_RUN_IFELSE(
-	[AC_LANG_SOURCE(
-		[[#include <mozilla-config.h>
-		  #include <string.h>
-		  #include <stdlib.h>
-                  int main(void) {
-		    if (strcmp (MOZ_DEFAULT_TOOLKIT, "gtk2") == 0 ||
-		        strcmp (MOZ_DEFAULT_TOOLKIT, "cairo-gtk2") == 0)
-			    return EXIT_SUCCESS;
-		
-		    return EXIT_FAILURE;
-		  } ]]
-	)],
-	[result=yes],
-	[AC_MSG_ERROR([[This program needs a gtk 2 gecko build]])],
-        [result=maybe])
-AC_MSG_RESULT([$result])
-
 AC_MSG_CHECKING([[whether we have a gecko debug build]])
 AC_COMPILE_IFELSE(
 	[AC_LANG_SOURCE(
@@ -304,7 +285,9 @@ if (!stream) return 126;
 #ifdef MOZILLA_1_8_BRANCH
 version = "1.8.1";
 #else
-if (strncmp (MOZILLA_VERSION, "1.9", strlen ("1.9")) == 0) {
+if (strncmp (MOZILLA_VERSION, "2.0", strlen ("2.0")) == 0) {
+	version = "2.0";
+} else if (strncmp (MOZILLA_VERSION, "1.9", strlen ("1.9")) == 0) {
 	version = "1.9";
 } else if (strncmp (MOZILLA_VERSION, "1.8", strlen ("1.8")) == 0) {
 	version = "1.8";
@@ -328,7 +311,7 @@ AC_LANG_POP([C++])
 
 gecko_cv_gecko_version_int="$(echo "$gecko_cv_gecko_version" | $AWK -F . '{print [$]1 * 1000000 + [$]2 * 1000 + [$]3}')"
 
-if test "$gecko_cv_gecko_version_int" -lt "1007000" -o "$gecko_cv_gecko_version_int" -gt "1009000"; then
+if test "$gecko_cv_gecko_version_int" -lt "1007000" -o "$gecko_cv_gecko_version_int" -gt "2000000"; then
 	AC_MSG_ERROR([Gecko version $gecko_cv_gecko_version is not supported!])
 fi
 
@@ -350,7 +333,10 @@ if test "$gecko_cv_gecko_version_int" -g
 fi
 
 if test "${gecko_cv_gecko}" = "libxul-embedding" -o "${gecko_cv_gecko}" = "libxul"; then
-	PKG_CHECK_EXISTS([${gecko_cv_gecko} >= 1.9.1],[gecko_cv_have_gecko_1_9_1=yes gecko_cv_gecko_version="1.9.1" gecko_cv_gecko_version_int=1009001],[gecko_cv_have_gecko_1_9_1=no])
+	PKG_CHECK_EXISTS([${gecko_cv_gecko} >= 1.9.1],
+        [ gecko_cv_have_gecko_1_9_1=yes
+          if test "$gecko_cv_gecko_version_int" -lt "2000000"; then gecko_cv_gecko_version="1.9.1" gecko_cv_gecko_version_int=1009001; fi
+        ],[gecko_cv_have_gecko_1_9_1=no])
 else
 	gecko_cv_have_gecko_1_9_1=no
 fi
@@ -359,6 +345,11 @@ if test "$gecko_cv_have_gecko_1_9_1" = "
         AC_DEFINE([HAVE_GECKO_1_9_1],[1],[Define if we have gecko 1.9.1])
 fi
 
+if test "$gecko_cv_gecko_version_int" -ge "2000000"; then
+	AC_DEFINE([HAVE_GECKO_2_0],[1],[Define if we have gecko 2.0])
+	gecko_cv_have_gecko_2_0=yes
+fi
+
 fi # if gecko_cv_have_gecko
 
 $1[]_VERSION=$gecko_cv_gecko_version
@@ -407,6 +398,7 @@ AM_CONDITIONAL([HAVE_GECKO_1_8],[test "$
 AM_CONDITIONAL([HAVE_GECKO_1_8_1],[test "$gecko_cv_have_gecko" = "yes" -a "$gecko_cv_gecko_version_int" -ge "1008001"])
 AM_CONDITIONAL([HAVE_GECKO_1_9],[test "$gecko_cv_have_gecko" = "yes" -a "$gecko_cv_gecko_version_int" -ge "1009000"])
 AM_CONDITIONAL([HAVE_GECKO_1_9_1],[test "$gecko_cv_have_gecko" = "yes" -a "$gecko_cv_have_gecko_1_9_1" = "yes"])
+AM_CONDITIONAL([HAVE_GECKO_2_0],[test "$gecko_cv_have_gecko" = "yes" -a "$gecko_cv_have_gecko_2_0" = "yes"])
 AM_CONDITIONAL([HAVE_GECKO_HOME],[test "x$_GECKO_HOME" != "x"])
 AM_CONDITIONAL([HAVE_GECKO_DEBUG],[test "$gecko_cv_have_debug" = "yes"])
 AM_CONDITIONAL([HAVE_GECKO_XPCOM_GLUE],[test "$gecko_cv_have_xpcom_glue" = "yes"])
