$NetBSD: patch-ext_sqlite3_libsqlite_sqlite3.c,v 1.1 2015/06/17 12:26:14 fhajny Exp $

Don't redefine _XOPEN_SOURCE, it is already set from php.

--- ext/sqlite3/libsqlite/sqlite3.c.orig	2015-06-10 05:11:55.000000000 +0000
+++ ext/sqlite3/libsqlite/sqlite3.c
@@ -8408,7 +8408,7 @@ struct sqlite3_rtree_query_info {
 ** But _XOPEN_SOURCE define causes problems for Mac OS X, so omit
 ** it.
 */
-#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__)
+#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && !defined(__sun)
 #  define _XOPEN_SOURCE 600
 #endif
 
