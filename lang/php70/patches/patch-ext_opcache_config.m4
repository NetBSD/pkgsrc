$NetBSD: patch-ext_opcache_config.m4,v 1.3 2016/04/02 13:02:36 taca Exp $

* Fix using of "==" for test(1).

--- ext/opcache/config.m4.orig	2016-03-29 14:44:24.000000000 +0000
+++ ext/opcache/config.m4
@@ -376,7 +376,7 @@ AC_TRY_RUN([
     AC_MSG_RESULT("yes")
 ], AC_MSG_RESULT("no") )
 
-if test "$flock_type" == "unknown"; then
+if test "$flock_type" = "unknown"; then
 	AC_MSG_ERROR([Don't know how to define struct flock on this system[,] set --enable-opcache=no])
 fi
 
