$NetBSD: patch-ext_opcache_config.m4,v 1.1 2014/11/24 15:37:08 taca Exp $

Avoid use "==" in test(1).

--- ext/opcache/config.m4.orig	2014-11-12 13:52:21.000000000 +0000
+++ ext/opcache/config.m4
@@ -359,7 +359,7 @@ AC_TRY_RUN([
     AC_MSG_RESULT("yes")
 ], AC_MSG_RESULT("no") )
 
-if test "$flock_type" == "unknown"; then
+if test "$flock_type" = "unknown"; then
 	AC_MSG_ERROR([Don't know how to define struct flock on this system[,] set --enable-opcache=no])
 fi
 
