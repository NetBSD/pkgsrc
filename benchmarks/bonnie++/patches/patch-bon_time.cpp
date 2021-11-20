$NetBSD: patch-bon_time.cpp,v 1.1 2021/11/20 05:57:29 rin Exp $

Cast double variable into int when printf with %d.

--- bon_time.cpp.orig	2021-11-18 11:35:23.646872320 +0900
+++ bon_time.cpp	2021-11-18 11:36:15.386982308 +0900
@@ -146,7 +146,7 @@ int BonTimer::print_stat(tests_t test, i
         }
         else
         {
-          fprintf(m_fp, " %5d", stat);
+          fprintf(m_fp, " %5d", (int)stat);
         }
       }
       else
