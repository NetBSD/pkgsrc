$NetBSD: patch-ext_sqlite3_libsqlite_sqlite3.c,v 1.1 2014/11/24 15:37:08 taca Exp $$
Don't redefine _XOPEN_SOURCE, it is already set from php.

--- ext/sqlite3/libsqlite/sqlite3.c.orig	2014-11-12 13:52:21.000000000 +0000
+++ ext/sqlite3/libsqlite/sqlite3.c
@@ -7867,7 +7867,7 @@ struct sqlite3_rtree_geometry {
 ** But _XOPEN_SOURCE define causes problems for Mac OS X, so omit
 ** it.
 */
-#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__)
+#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && !defined(__sun)
 #  define _XOPEN_SOURCE 600
 #endif
 
