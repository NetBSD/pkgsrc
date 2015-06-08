$NetBSD: patch-client_misc.c,v 1.1 2015/06/08 13:38:12 joerg Exp $

--- client/misc.c.orig	2015-06-08 12:34:33.000000000 +0000
+++ client/misc.c
@@ -81,8 +81,7 @@ dodump(const char *name)
     }
     for (y = 0; y <= maxy; y++) {
 	for (x = 0; x < maxx; x++)  {
-	    char c;
-	    mvinsnstr(y, x, &c, 1);
+	    char c = mvgetch(y, x);
 	    (void) putc(c & 0177, fp);
 	}
 	(void) putc('\n', fp);
