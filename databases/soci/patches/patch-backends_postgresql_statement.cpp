$NetBSD: patch-backends_postgresql_statement.cpp,v 1.1 2013/10/04 18:32:07 joerg Exp $

--- backends/postgresql/statement.cpp.orig	2013-10-02 07:33:45.455669800 +0000
+++ backends/postgresql/statement.cpp
@@ -453,7 +453,7 @@ long long postgresql_statement_backend::
     // pointer to it, so we can't rely on implicit conversion here.
     const char * const resultStr = PQcmdTuples(result_.get_result());
     char * end;
-    long long result = std::strtoll(resultStr, &end, 0);
+    long long result = strtoll(resultStr, &end, 0);
     if (end != resultStr)
     {
         return result;
