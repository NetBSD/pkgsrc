$NetBSD: patch-ext_sqlite3_libsqlite_sqlite3.c,v 1.1 2014/04/14 10:17:19 jperkin Exp $

Don't redefine _XOPEN_SOURCE, it is already set from php.

--- ext/sqlite3/libsqlite/sqlite3.c.orig	2014-04-01 12:32:03.000000000 +0000
+++ ext/sqlite3/libsqlite/sqlite3.c
@@ -7822,7 +7822,7 @@ struct sqlite3_rtree_geometry {
 ** But _XOPEN_SOURCE define causes problems for Mac OS X, so omit
 ** it.
 */
-#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__)
+#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && !defined(__sun)
 #  define _XOPEN_SOURCE 600
 #endif
 
