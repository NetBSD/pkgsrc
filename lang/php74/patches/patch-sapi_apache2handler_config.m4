$NetBSD: patch-sapi_apache2handler_config.m4,v 1.2 2025/02/08 02:58:55 taca Exp $

* Don't autodetect maintainer-zts.
* Adjust PHP library name.

--- sapi/apache2handler/config.m4.orig	2022-10-31 10:36:05.000000000 +0000
+++ sapi/apache2handler/config.m4
@@ -67,14 +67,14 @@ if test "$PHP_APXS2" != "no"; then
   if test -z `$APXS -q SYSCONFDIR`; then
     INSTALL_IT="\$(mkinstalldirs) '$APXS_LIBEXECDIR' && \
                  $APXS -S LIBEXECDIR='$APXS_LIBEXECDIR' \
-                       -i -n php7"
+                       -i -n php$PHP_VER"
   else
     APXS_SYSCONFDIR='$(INSTALL_ROOT)'`$APXS -q SYSCONFDIR`
     INSTALL_IT="\$(mkinstalldirs) '$APXS_LIBEXECDIR' && \
                 \$(mkinstalldirs) '$APXS_SYSCONFDIR' && \
                  $APXS -S LIBEXECDIR='$APXS_LIBEXECDIR' \
                        -S SYSCONFDIR='$APXS_SYSCONFDIR' \
-                       -i -a -n php7"
+                       -i -a -n php$PHP_VER"
   fi
 
   case $host_alias in
@@ -96,7 +96,7 @@ if test "$PHP_APXS2" != "no"; then
     MH_BUNDLE_FLAGS="-bundle -bundle_loader $APXS_HTTPD $MH_BUNDLE_FLAGS"
     PHP_SUBST(MH_BUNDLE_FLAGS)
     PHP_SELECT_SAPI(apache2handler, bundle, mod_php7.c sapi_apache2.c apache_config.c php_functions.c, $APACHE_CFLAGS)
-    SAPI_SHARED=libs/libphp7.so
+    SAPI_SHARED=libs/libphp$PHP_VER.so
     INSTALL_IT="$INSTALL_IT $SAPI_SHARED"
     ;;
   *)
@@ -105,17 +105,6 @@ if test "$PHP_APXS2" != "no"; then
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
   AC_MSG_RESULT(yes)
   PHP_SUBST(APXS)
 else
