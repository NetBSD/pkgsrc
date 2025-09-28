$NetBSD: patch-src_SqliteResultImpl.h,v 1.1 2025/09/28 22:23:43 brook Exp $

Misplaced attribute: see https://www.cppreference.com/w/cpp/language/declarations.html

Upstream bug report #633: NORET attribute is misplaced

--- src/SqliteResultImpl.h.orig	2025-05-02 09:14:28.000000000 +0000
+++ src/SqliteResultImpl.h
@@ -72,8 +72,8 @@ private:
   cpp11::list peek_first_row();
 
 private:
-  void NORET raise_sqlite_exception() const;
-  static void NORET raise_sqlite_exception(sqlite3* conn);
+  NORET void raise_sqlite_exception() const;
+  NORET static void raise_sqlite_exception(sqlite3* conn);
 };
 
 
