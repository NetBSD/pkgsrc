$NetBSD: patch-sapi_apache_config.m4,v 1.1 2025/02/08 02:57:59 taca Exp $

* Adjust PHP library name.

--- sapi/apache/config.m4.orig	2019-01-09 09:54:13.000000000 +0000
+++ sapi/apache/config.m4
@@ -78,7 +78,7 @@ if test "$PHP_APXS" != "no"; then
   *darwin*)
     MH_BUNDLE_FLAGS="-dynamic -twolevel_namespace -bundle -bundle_loader $APXS_HTTPD"
     PHP_SUBST(MH_BUNDLE_FLAGS)
-    SAPI_SHARED=libs/libphp5.so
+    SAPI_SHARED=libs/libphp$PHP_VER.so
     build_type=bundle
     ;;
   *)
@@ -135,7 +135,7 @@ if test "$PHP_SAPI" != "apache" && test 
     PHP_APACHE=/usr/local/apache
   fi
 
-  APACHE_INSTALL_FILES="\$(srcdir)/sapi/apache/mod_php5.* sapi/apache/libphp5.module"
+  APACHE_INSTALL_FILES="\$(srcdir)/sapi/apache/mod_php5.* sapi/apache/libphp$PHP_VER.module"
 
   AC_DEFINE(HAVE_APACHE,1,[ ])
   APACHE_MODULE=yes
@@ -247,7 +247,7 @@ dnl Build as static module
 if test "$APACHE_MODULE" = "yes"; then
   PHP_TARGET_RDYNAMIC
   $php_shtool mkdir -p sapi/apache
-  PHP_OUTPUT(sapi/apache/libphp5.module)
+  PHP_OUTPUT(sapi/apache/libphp$PHP_VER.module)
 fi
 
 dnl General
