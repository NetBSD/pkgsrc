$NetBSD: patch-sapi_apache2handler_config.m4,v 1.1 2024/06/07 13:57:24 taca Exp $

Don't autodetect maintainer-zts.

--- sapi/apache2handler/config.m4.orig	2024-06-04 14:53:17.000000000 +0000
+++ sapi/apache2handler/config.m4
@@ -108,18 +108,6 @@ if test "$PHP_APXS2" != "no"; then
     ;;
   esac
 
-  if test "$APACHE_VERSION" -lt 2004001; then
-    APXS_MPM=`$APXS -q MPM_NAME`
-    if test "$APXS_MPM" != "prefork" && test "$APXS_MPM" != "peruser" && test "$APXS_MPM" != "itk"; then
-      PHP_BUILD_THREAD_SAFE
-    fi
-  else
-    APACHE_THREADED_MPM=`$APXS_HTTPD -V 2>/dev/null | grep 'threaded:.*yes'`
-    if test -n "$APACHE_THREADED_MPM"; then
-      PHP_BUILD_THREAD_SAFE
-    fi
-  fi
-  AC_MSG_RESULT(yes)
   PHP_SUBST(APXS)
 else
   AC_MSG_RESULT(no)
