$NetBSD: patch-sapi_apache2handler_config.m4,v 1.1 2026/01/08 13:38:00 taca Exp $

* Don't autodetect maintainer-zts.
* Add $PHP_VER suffix.

--- sapi/apache2handler/config.m4.orig	2025-05-06 12:31:58.000000000 +0000
+++ sapi/apache2handler/config.m4
@@ -72,14 +72,14 @@ if test "$PHP_APXS2" != "no"; then
   if test -z $($APXS -q SYSCONFDIR); then
     INSTALL_IT="\$(mkinstalldirs) '$APXS_LIBEXECDIR' && \
                  $APXS -S LIBEXECDIR='$APXS_LIBEXECDIR' \
-                       -i -n php"
+                       -i -n php$PHP_VER"
   else
     APXS_SYSCONFDIR='$(INSTALL_ROOT)'$($APXS -q SYSCONFDIR)
     INSTALL_IT="\$(mkinstalldirs) '$APXS_LIBEXECDIR' && \
                 \$(mkinstalldirs) '$APXS_SYSCONFDIR' && \
                  $APXS -S LIBEXECDIR='$APXS_LIBEXECDIR' \
                        -S SYSCONFDIR='$APXS_SYSCONFDIR' \
-                       -i -a -n php"
+                       -i -a -n php$PHP_VER"
   fi
 
   LIBPHP_CFLAGS="-shared"
@@ -119,22 +119,4 @@ if test "$PHP_APXS2" != "no"; then
       $APU_CFLAGS
       -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1
     ])
-
-  AS_IF([$APXS_HTTPD -V 2>/dev/null | grep 'threaded:.*yes' >/dev/null 2>&1], [
-    APACHE_THREADED_MPM=yes
-    enable_zts=yes
-  ], [APACHE_THREADED_MPM=no])
-
-AC_CONFIG_COMMANDS([apache2handler], [AS_VAR_IF([enable_zts], [yes],,
-  [AS_VAR_IF([APACHE_THREADED_MPM], [no],
-    [AC_MSG_WARN([
-+--------------------------------------------------------------------+
-|                        *** WARNING ***                             |
-|                                                                    |
-| You have built PHP for Apache's current non-threaded MPM.          |
-| If you change Apache to use a threaded MPM you must reconfigure    |
-| PHP with --enable-zts                                              |
-+--------------------------------------------------------------------+
-  ])])])],
-  [APACHE_THREADED_MPM="$APACHE_THREADED_MPM"; enable_zts="$enable_zts"])
 fi
