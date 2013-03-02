$NetBSD: patch-host.c,v 1.1 2013/03/02 17:59:41 joerg Exp $

--- host.c.orig	2013-03-01 13:59:50.000000000 +0000
+++ host.c
@@ -96,8 +96,7 @@ int host;
  *                   to "host" is detected.  The user is informed, and a
  *                   reconnection is attempted if he/she wishes.
  */
-lost_connection(host)
-int host;
+void lost_connection(int host)
 {
 	char msg[250];
 	static char *side[] = { "left", "right" };
