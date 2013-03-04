$NetBSD: patch-subs.c,v 1.1 2013/03/04 14:45:07 joerg Exp $

--- subs.c.orig	2013-03-01 15:11:50.000000000 +0000
+++ subs.c
@@ -429,7 +429,7 @@ int cliplast(char *lastbuf, int bufsize)
 #endif
 
     /* Make a copy of the file */
-    if ((cfp= make_copy()) == NULL) return;
+    if ((cfp= make_copy()) == NULL) return 0;
     fflush(cfp);
     fseek(cfp,0L,0);
 
