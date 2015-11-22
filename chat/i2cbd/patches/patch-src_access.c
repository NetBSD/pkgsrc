$NetBSD: patch-src_access.c,v 1.2 2015/11/22 17:17:33 dholland Exp $

Fix bounding errors detected by OpenBSD's compiler.

--- src/access.c~	2006-05-11 03:44:52.000000000 +0000
+++ src/access.c
@@ -341,7 +341,7 @@ nickreadmsg(int forWhom)
 				strncpy(from, data.data, data.size);
 				from[data.size] = '\0';
 			} else
-				strlcpy(from, "Server", LINE_SIZE);
+				strlcpy(from, "Server", sizeof(from));
 			userdb->del(userdb, &key, 0);
 
 			snprintf(kbuf, KEY_SIZE, "%s.message%d", u_tab[forWhom].nickname, i);
@@ -581,7 +581,7 @@ nickwrite (int forWhom, const char *pass
 		snprintf(line, LINE_SIZE, "Nick registered");
 		sends_cmdout(forWhom, line);
 
-		strlcpy(u_tab[forWhom].realname, "registered", LINE_SIZE);
+		strlcpy(u_tab[forWhom].realname, "registered", sizeof(u_tab[forWhom].realname));
 		strlcpy(u_tab[forWhom].password, password, MAX_PASSWDLEN+1);
 		nickwritetime(forWhom, 0);
 	}
