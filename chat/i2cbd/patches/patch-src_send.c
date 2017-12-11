$NetBSD: patch-src_send.c,v 1.1 2017/12/11 07:54:42 spz Exp $

fix copy length

--- src/send.c.orig	2006-05-11 03:44:53.000000000 +0000
+++ src/send.c
@@ -163,7 +163,7 @@ s_new_user(int n)
 		return;
 		}
 	snprintf(line, LINE_SIZE, "[CONNECT] %d: %s", n, cp);
-	strlcpy(u_tab[n].nodeid, cp, MAX_NODELEN);
+	strlcpy(u_tab[n].nodeid, cp, MAX_NODELEN+1);
 	MDB(line);
 }
 
