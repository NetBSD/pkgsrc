$NetBSD: patch-uip_forw.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/forw.c.orig	2013-03-28 18:15:26.000000000 +0000
+++ uip/forw.c
@@ -22,7 +22,8 @@ static char ident[] = "@(#)$Id: forw.c,v
 #define	IFORMAT	"digest-issue-%s"
 #define	VFORMAT	"digest-volume-%s"
 
-static	mhl_draft(), copy_draft(), build_form();
+static	mhl_draft(), build_form();
+static void copy_draft (int out, char *digest, char *file, int volume, int issue, int mime);
 /*  */
 
 static struct swit switches[] = {
@@ -558,13 +559,7 @@ register char   *digest,
 
 /*  */
 
-static	copy_draft (out, digest, file, volume, issue, mime)
-int     out,
-        volume,
-        issue,
-	mime;
-register char   *digest,
-		*file;
+static void copy_draft (int out, char *digest, char *file, int volume, int issue, int mime)
 {
     int     fd,i,
             msgcnt,
