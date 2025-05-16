$NetBSD: patch-playhouse___sqlite__ext.pyx,v 1.1 2025/05/16 08:41:37 adam Exp $

Remove long check for newer cython.
https://github.com/dumpmemory/peewee/commit/3aadae7eb3602f3ab893343045aa30d427985534

--- playhouse/_sqlite_ext.pyx.orig	2025-05-16 08:36:42.494699930 +0000
+++ playhouse/_sqlite_ext.pyx
@@ -326,7 +326,7 @@ cdef sqlite_to_python(int argc, sqlite3_
 cdef python_to_sqlite(sqlite3_context *context, value):
     if value is None:
         sqlite3_result_null(context)
-    elif isinstance(value, (int, long)):
+    elif isinstance(value, int):
         sqlite3_result_int64(context, <sqlite3_int64>value)
     elif isinstance(value, float):
         sqlite3_result_double(context, <double>value)
