$NetBSD: patch-src_s__user.c,v 1.1 2017/12/11 07:54:42 spz Exp $

fix copy length

--- src/s_user.c.orig	2006-05-11 03:44:53.000000000 +0000
+++ src/s_user.c
@@ -277,7 +277,7 @@ s_name(int n, int argc)
 		snprintf(line, LINE_SIZE, "%s changed nickname to %s", u_tab[n].nickname, new_name);
                 s_status_group(1,0,n,"Name",line);
 		nickwritetime(n, 1);
-		strlcpy(u_tab[n].nickname, new_name, MAX_NICKLEN);
+		strlcpy(u_tab[n].nickname, new_name, MAX_NICKLEN+1);
 
 		/* side-effects:
 			inform folx in same group of change
@@ -290,7 +290,7 @@ s_name(int n, int argc)
 	        ret = nicklookup(-n, u_tab[n].nickname);
 	        if (ret == 0) {
 	                /* we know this person */
-	                strlcpy(u_tab[n].realname, "registered", MAX_REALLEN);
+	                strlcpy(u_tab[n].realname, "registered", MAX_REALLEN+1);
 			sends_cmdout(n, "Nick registered");
 			nickwritetime(n, 0);
 			for (i = 1; i < MAX_GROUPS; i++)
