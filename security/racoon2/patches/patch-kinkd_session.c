$NetBSD: patch-kinkd_session.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Fix pointer to integer cast

--- kinkd/session.c.orig	2006-08-11 16:44:34.000000000 -0400
+++ kinkd/session.c	2018-05-28 21:09:41.263580997 -0400
@@ -290,7 +290,7 @@
 {
 	int signo;
 
-	signo = (int)arg;
+	signo = (int)(intptr_t)arg;
 
 	switch (signo) {
 	case SIGHUP:
