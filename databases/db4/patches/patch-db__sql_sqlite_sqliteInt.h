$NetBSD: patch-db__sql_sqlite_sqliteInt.h,v 1.1 2016/09/08 16:10:24 jperkin Exp $

Support SunOS in C99 mode.

--- db_sql/sqlite/sqliteInt.h.orig	2010-04-12 20:25:22.000000000 +0000
+++ db_sql/sqlite/sqliteInt.h
@@ -168,7 +168,7 @@
 **
 ** See also ticket #2741.
 */
-#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && SQLITE_THREADSAFE
+#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && SQLITE_THREADSAFE && !(defined(__sun) && (__STDC_VERSION__ - 0 >= 199901L))
 #  define _XOPEN_SOURCE 500  /* Needed to enable pthread recursive mutexes */
 #endif
 
