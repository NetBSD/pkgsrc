$NetBSD: patch-sapi_apache2handler_config.m4,v 1.1 2025/02/22 15:27:56 taca Exp $

* Don't autodetect maintainer-zts.
* Add $PHP_VER suffix.

--- sapi/apache2handler/config.m4.orig	2025-01-15 01:03:17.000000000 +0000
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
