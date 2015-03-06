$NetBSD: patch-estd.c,v 1.1 2015/03/06 18:08:38 khorben Exp $

Removed useless "estd: Forked" message

--- estd.c.orig	2015-02-18 21:38:03.000000000 +0000
+++ estd.c
@@ -626,7 +626,6 @@ main(int argc, char *argv[])
 	/* all ok, here we go */
 	if (daemonize) {
 		if (fork()) {
-			printf("estd: Forked\n");
 			exit(0);
 		}
 	} else {
