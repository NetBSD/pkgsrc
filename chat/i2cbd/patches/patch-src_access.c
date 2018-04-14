$NetBSD: patch-src_access.c,v 1.4 2018/04/14 22:13:16 christos Exp $

Fix bounding errors detected by OpenBSD's compiler.
Fix indent errors found by gcc 6
don't cut off realnames or passwords

--- src/access.c.orig	2006-05-10 23:44:52.000000000 -0400
+++ src/access.c	2018-04-14 18:07:48.416319696 -0400
@@ -341,7 +341,7 @@
 				strncpy(from, data.data, data.size);
 				from[data.size] = '\0';
 			} else
-				strlcpy(from, "Server", LINE_SIZE);
+				strlcpy(from, "Server", sizeof(from));
 			userdb->del(userdb, &key, 0);
 
 			snprintf(kbuf, KEY_SIZE, "%s.message%d", u_tab[forWhom].nickname, i);
@@ -461,7 +461,7 @@
 		strncpy(line, data.data, data.size);
 		line[data.size] = '\0';
 
-		if (strncmp(line, oldpw, MAX_PASSWDLEN)) {
+		if (strncmp(line, oldpw, MAX_PASSWDLEN+1)) {
 			snprintf(line, LINE_SIZE, "Authorization failure");
 			senderror(forWhom, line);
 		} else {
@@ -522,7 +522,7 @@
 			snprintf(line, LINE_SIZE, "Nick registered");
 			sends_cmdout(forWhom, line);
 
-			strlcpy(u_tab[forWhom].realname, "registered", MAX_REALLEN);
+			strlcpy(u_tab[forWhom].realname, "registered", MAX_REALLEN+1);
 			strlcpy(u_tab[forWhom].password, password, MAX_PASSWDLEN+1);
 			nickwritetime(forWhom, 0);
 
@@ -581,7 +581,7 @@
 		snprintf(line, LINE_SIZE, "Nick registered");
 		sends_cmdout(forWhom, line);
 
-		strlcpy(u_tab[forWhom].realname, "registered", LINE_SIZE);
+		strlcpy(u_tab[forWhom].realname, "registered", sizeof(u_tab[forWhom].realname));
 		strlcpy(u_tab[forWhom].password, password, MAX_PASSWDLEN+1);
 		nickwritetime(forWhom, 0);
 	}
@@ -807,11 +807,12 @@
 						p++;
 					}
 				}
-				if (count > 0)
+				if (count > 0) {
 					strlcpy(temp, "Text: ", LINE_SIZE);
 					strlcat(temp, s, LINE_SIZE);
 					sends_cmdout(forWhom, temp);
 				}
+			}
 		} else {
 			snprintf(temp, LINE_SIZE, "%s@%s", u_tab[-forWhom].loginid, u_tab[-forWhom].nodeid);
 			strncpy(line, data.data, data.size);
