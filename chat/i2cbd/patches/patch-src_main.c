$NetBSD: patch-src_main.c,v 1.1 2017/12/11 07:54:42 spz Exp $

fix daemon call
fix copy length

--- src/main.c.orig	2006-05-11 03:44:52.000000000 +0000
+++ src/main.c
@@ -113,7 +113,7 @@ main (int argc, char **argv)
 		}
 
 		if (noforkflag == 0)
-			daemon(0,0);
+			daemon(1,0);
 
 		pidfile("icbd");
 
@@ -132,7 +132,7 @@ main (int argc, char **argv)
 		u_tab[NICKSERV].login = 1;
 		u_tab[NICKSERV].t_on = TheTime;
 		u_tab[NICKSERV].t_recv = TheTime;
-		strlcpy(u_tab[NICKSERV].realname, "registered", MAX_NICKLEN);
+		strlcpy(u_tab[NICKSERV].realname, "registered", MAX_NICKLEN+1);
 		fill_group_entry(0, "ICB", "...here to serve you!", SUPERSECRET, RESTRICTED, NICKSERV, QUIET);
 		nickwritetime(NICKSERV, 0);
 
