$NetBSD: patch-src_ipcf.c,v 1.1 2017/12/11 07:54:42 spz Exp $

fix copy length

--- src/ipcf.c.orig	2006-05-11 03:44:52.000000000 +0000
+++ src/ipcf.c
@@ -217,7 +217,7 @@ s_lost_user(int n)
 		   snprintf(line, LINE_SIZE, "Your group moderator signed off. (%d second timeout)", (int) MOD_TIMEOUT);
 		   s_status_group(2,0,was_mod, "Mod", line);
 		   g_tab[was_mod].mod = -1;
-		   strlcpy(g_tab[was_mod].missingmod, t_name, MAX_NICKLEN);
+		   strlcpy(g_tab[was_mod].missingmod, t_name, MAX_NICKLEN+1);
 		   TheTime = time(NULL);
 		   g_tab[was_mod].modtimeout = TheTime + MOD_TIMEOUT;
 		   }
