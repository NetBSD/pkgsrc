$NetBSD: patch-ext_sqlite3_config0.m4,v 1.1 2024/12/01 16:11:56 taca Exp $

* Do try to install sqlite3 header.

--- ext/sqlite3/config0.m4.orig	2019-01-09 09:54:13.000000000 +0000
+++ ext/sqlite3/config0.m4
@@ -83,7 +83,7 @@ if test $PHP_SQLITE3 != "no"; then
     fi
 
     PHP_SQLITE3_CFLAGS="-I@ext_srcdir@/libsqlite $other_flags $threadsafe_flags $debug_flags"
-    PHP_INSTALL_HEADERS([ext/sqlite3/libsqlite/sqlite3.h])
+    PHP_INSTALL_HEADERS([])
   fi
 
   AC_DEFINE(HAVE_SQLITE3,1,[ ])
