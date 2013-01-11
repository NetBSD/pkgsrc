$NetBSD: patch-maxsess.c,v 1.1 2013/01/11 00:03:30 joerg Exp $

--- maxsess.c.orig	2013-01-10 22:38:52.000000000 +0000
+++ maxsess.c
@@ -220,8 +220,7 @@ struct identity *idp;
  * Given a start or a stop accounting record, update the file of
  * records which tracks who's logged on and where.
  */
-loguser(rec)
-struct acct_rec *rec;
+void loguser(struct acct_rec *rec)
 {
     struct identity *idp;
     int i;
