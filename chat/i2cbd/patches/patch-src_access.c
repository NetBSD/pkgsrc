$NetBSD: patch-src_access.c,v 1.3 2017/12/11 07:54:42 spz Exp $

Fix bounding errors detected by OpenBSD's compiler.

don't cut off realnames or passwords

--- src/access.c.orig	2006-05-11 03:44:52.000000000 +0000
+++ src/access.c
@@ -341,7 +341,7 @@ nickreadmsg(int forWhom)
 				strncpy(from, data.data, data.size);
 				from[data.size] = '\0';
 			} else
-				strlcpy(from, "Server", LINE_SIZE);
+				strlcpy(from, "Server", sizeof(from));
 			userdb->del(userdb, &key, 0);
 
 			snprintf(kbuf, KEY_SIZE, "%s.message%d", u_tab[forWhom].nickname, i);
@@ -461,7 +461,7 @@ nickchpass(int forWhom, const char *oldp
 		strncpy(line, data.data, data.size);
 		line[data.size] = '\0';
 
-		if (strncmp(line, oldpw, MAX_PASSWDLEN)) {
+		if (strncmp(line, oldpw, MAX_PASSWDLEN+1)) {
 			snprintf(line, LINE_SIZE, "Authorization failure");
 			senderror(forWhom, line);
 		} else {
@@ -522,7 +522,7 @@ nickwrite (int forWhom, const char *pass
 			snprintf(line, LINE_SIZE, "Nick registered");
 			sends_cmdout(forWhom, line);
 
-			strlcpy(u_tab[forWhom].realname, "registered", MAX_REALLEN);
+			strlcpy(u_tab[forWhom].realname, "registered", MAX_REALLEN+1);
 			strlcpy(u_tab[forWhom].password, password, MAX_PASSWDLEN+1);
 			nickwritetime(forWhom, 0);
 
@@ -581,7 +581,7 @@ nickwrite (int forWhom, const char *pass
 		snprintf(line, LINE_SIZE, "Nick registered");
 		sends_cmdout(forWhom, line);
 
-		strlcpy(u_tab[forWhom].realname, "registered", LINE_SIZE);
+		strlcpy(u_tab[forWhom].realname, "registered", sizeof(u_tab[forWhom].realname));
 		strlcpy(u_tab[forWhom].password, password, MAX_PASSWDLEN+1);
 		nickwritetime(forWhom, 0);
 	}
