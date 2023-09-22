$NetBSD: patch-src_ODBCStatement.h,v 1.1 2023/09/22 09:18:21 nros Exp $

* use std::pow, fixes:
  "error: call to overloaded function is ambigous" on Illumos

--- src/ODBCStatement.h.orig	2023-09-22 11:14:02.210099653 +0000
+++ src/ODBCStatement.h
@@ -1149,7 +1149,7 @@ TIMESTAMP_STRUCT ODBCStatement::getTimes
     if (options.frPrec >= 6) { // 6-9
         t.fraction = info.us * 1000;
     } else { // 1-5
-        int n = pow(10, 6-options.frPrec);
+        int n = std::pow(10, 6-options.frPrec);
         t.fraction = info.us / n;
         t.fraction *= n * 1000;
     }
@@ -1238,7 +1238,7 @@ SQL_INTERVAL_STRUCT ODBCStatement::getSe
         i.intval.day_second.fraction = abs(arg->getMicrosecond()) * 1000;
     }
     else { // 1-5
-        int n = pow(10, 6-options.frPrec);
+        int n = std::pow(10, 6-options.frPrec);
         i.intval.day_second.fraction = abs(arg->getMicrosecond()) / n;
         i.intval.day_second.fraction *= n * 1000;
     }
@@ -1280,7 +1280,7 @@ SQL_INTERVAL_STRUCT ODBCStatement::getDa
         i.intval.day_second.fraction = abs(arg->getMicrosecond()) * 1000;
     }
     else { // 1-5
-        int n = pow(10, 6-options.frPrec);
+        int n = std::pow(10, 6-options.frPrec);
         i.intval.day_second.fraction = abs(arg->getMicrosecond()) / n;
         i.intval.day_second.fraction *= n * 1000;
     }
@@ -1310,7 +1310,7 @@ SQL_INTERVAL_STRUCT ODBCStatement::getHo
         i.intval.day_second.fraction = abs(arg->getMicrosecond()) * 1000;
     }
     else { // 1-5
-        int n = pow(10, 6-options.frPrec);
+        int n = std::pow(10, 6-options.frPrec);
         i.intval.day_second.fraction = abs(arg->getMicrosecond()) / n;
         i.intval.day_second.fraction *= n * 1000;
     }
@@ -1329,7 +1329,7 @@ SQL_INTERVAL_STRUCT ODBCStatement::getMi
         i.intval.day_second.fraction = abs(arg->getMicrosecond()) * 1000;
     }
     else { // 1-5
-        int n = pow(10, 6-options.frPrec);
+        int n = std::pow(10, 6-options.frPrec);
         i.intval.day_second.fraction = abs(arg->getMicrosecond()) / n;
         i.intval.day_second.fraction *= n * 1000;
     }
