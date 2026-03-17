$NetBSD: patch-locktests.c,v 1.1 2026/03/17 15:00:29 nia Exp $

Recent GCC no longer likes implicit int.

--- locktests.c.orig	2026-03-17 14:51:47.381002077 +0000
+++ locktests.c
@@ -390,7 +390,7 @@ void selectTest(int n, struct s_test *te
     test->type=lockSuiv(n);
 }
 
-void rapport(clnt){
+void rapport(int clnt){
     int i;
     printf("\n%s number : %d\n", eType, clnt);
     printf("%s number running test successfully :\n",eType);
