$NetBSD: patch-src_os_pl-fmt.c,v 1.1 2014/04/16 21:03:51 joerg Exp $

--- src/os/pl-fmt.c.orig	2014-04-16 20:47:33.000000000 +0000
+++ src/os/pl-fmt.c
@@ -917,7 +917,7 @@ formatNumber(bool split, int div, int ra
       { char *s;
 
 	for(s=buf; *s; s++)
-	  *s = toupper(*s);
+	  *s = toupper((unsigned char)*s);
       }
       if ( split || div > 0 )
       { int before = (int)(len-div);
