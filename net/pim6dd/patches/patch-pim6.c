$NetBSD: patch-pim6.c,v 1.1 2013/09/10 14:36:37 joerg Exp $

--- pim6.c.orig	2013-09-10 12:21:48.000000000 +0000
+++ pim6.c
@@ -142,7 +142,7 @@ pim6_read(f, rfd)
 	fd_set *rfd;
 {
 	register int pim6_recvlen;
-	int fromlen = sizeof(from);
+	socklen_t fromlen = sizeof(from);
 #ifdef SYSV
 	sigset_t block, oblock;
 #else
