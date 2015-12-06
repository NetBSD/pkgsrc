$NetBSD: patch-ext_opcache_config.m4,v 1.1 2015/12/06 15:17:31 taca Exp $

--- ext/opcache/config.m4.orig	2015-12-01 13:36:41.000000000 +0000
+++ ext/opcache/config.m4
@@ -14,11 +14,11 @@ PHP_ARG_ENABLE(huge-code-pages, whether 
 
 if test "$PHP_OPCACHE" != "no"; then
 
-  if test "$PHP_OPCACHE_FILE" == "yes"; then
+  if test "$PHP_OPCACHE_FILE" = "yes"; then
     AC_DEFINE(HAVE_OPCACHE_FILE_CACHE, 1, [Define to enable file based caching (experimental)])
   fi
 
-  if test "$PHP_HUGE_CODE_PAGES" == "yes"; then
+  if test "$PHP_HUGE_CODE_PAGES" = "yes"; then
     AC_DEFINE(HAVE_HUGE_CODE_PAGES, 1, [Define to enable copying PHP CODE pages into HUGE PAGES (experimental)])
   fi
 
@@ -374,7 +374,7 @@ AC_TRY_RUN([
     AC_MSG_RESULT("yes")
 ], AC_MSG_RESULT("no") )
 
-if test "$flock_type" == "unknown"; then
+if test "$flock_type" = "unknown"; then
 	AC_MSG_ERROR([Don't know how to define struct flock on this system[,] set --enable-opcache=no])
 fi
 
