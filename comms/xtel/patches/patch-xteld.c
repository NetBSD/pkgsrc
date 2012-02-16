$NetBSD: patch-xteld.c,v 1.1 2012/02/16 18:00:20 hans Exp $

--- xteld.c.orig	2012-01-27 10:38:52.463694864 +0100
+++ xteld.c	2012-01-27 10:41:01.412450708 +0100
@@ -264,7 +264,7 @@ int code_erreur;
     }
     else if (type_client == CLIENT_W_HYPER) {
       if (e)
-	sprintf (buf, "%s: %s", s, sys_errlist[errno]);
+	sprintf (buf, "%s: %s", s, strerror(errno));
       else {
 	if (*s == '[')
 	  strcpy (buf, s + 3);
