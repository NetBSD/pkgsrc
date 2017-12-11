$NetBSD: patch-src_serverserve.c,v 1.1 2017/12/11 07:54:42 spz Exp $

when checking FD_ISSET also check for <0
start fd checks at 0

--- src/serverserve.c.orig	2006-05-11 03:50:28.000000000 +0000
+++ src/serverserve.c	2008-03-21 16:22:20.000000000 +0000
@@ -80,7 +80,7 @@
 		    for (i = 0; i < MAX_USERS+1; i++)
 		    {
 			/* if it's currently being held */
-			if (FD_ISSET(i, &held_fdset) > 0)
+			if (FD_ISSET(i, &held_fdset))
 			{
 			    /* add it to fdset and remove it from held */
 			    FD_SET (i, &fdset);
@@ -106,16 +106,16 @@
 {
 	int n, x, fcarg;
 
-	for (x = 1; x <= highestfd; x++)
-		if (FD_ISSET(x, &efdr) > 0) {
+	for (x = 0; x <= highestfd; x++)
+		if (FD_ISSET(x, &efdr)) {
 			disconnectuser(x);
 			}
 
 	/* examine set of file descriptors */
-	for (x = 1; x <= highestfd; x++) {
+	for (x = 0; x <= highestfd; x++) {
 		int closed = 0;
 
-		if (FD_ISSET(x, &fdr) > 0) {
+		if (FD_ISSET(x, &fdr)) {
 			if (FD_ISSET(x,&serversocks)) {
 				/* new connect on advertised socket */
 				if ((n = newconnect(x)) > 0)
