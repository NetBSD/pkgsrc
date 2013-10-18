$NetBSD: patch-ext_opcache_config.m4,v 1.1 2013/10/18 15:49:07 taca Exp $

Avoid use "==" in test(1).

--- ext/opcache/config.m4.orig	2013-10-15 13:49:47.000000000 +0000
+++ ext/opcache/config.m4
@@ -359,7 +359,7 @@ AC_TRY_RUN([
     AC_MSG_RESULT("yes")
 ], AC_MSG_RESULT("no") )
 
-if test "$flock_type" == "unknown"; then
+if test "$flock_type" = "unknown"; then
 	AC_MSG_ERROR([Don't know how to define struct flock on this system[,] set --enable-opcache=no])
 fi
   
