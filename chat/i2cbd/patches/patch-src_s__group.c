$NetBSD: patch-src_s__group.c,v 1.2 2018/04/14 22:13:16 christos Exp $

fix copy lengths
fix indentation for gcc-6

--- src/s_group.c.orig	2006-05-10 23:44:53.000000000 -0400
+++ src/s_group.c	2018-04-14 18:10:07.068923493 -0400
@@ -260,7 +260,7 @@
 			}
 			/* could create it, so fill in the info */
 			g_tab[ngi].visibility = visibility;
-			strlcpy(g_tab[ngi].name, n_g_n, MAX_GROUPLEN);
+			strlcpy(g_tab[ngi].name, n_g_n, MAX_GROUPLEN+1);
 			if (strcasecmp("1", n_g_n) != 0) {
 				g_tab[ngi].control = MODERATED;
 				g_tab[ngi].mod = n;
@@ -326,7 +326,7 @@
 		/* is the new group different than the old group? */
 		if (ngi != ogi) {
 			/* the group exists and we are allowed in. */
-			strlcpy(u_tab[n].group, g_tab[ngi].name, MAX_GROUPLEN);
+			strlcpy(u_tab[n].group, g_tab[ngi].name, MAX_GROUPLEN+1);
 
 			/* tell the new group about the arrival */
 			snprintf(line, LINE_SIZE, "%s (%s@%s) entered group", u_tab[n].nickname,
@@ -896,12 +896,12 @@
 								nlput(g_tab[gi].n_invites,u_tab[i].nickname);
 							   else
 								nlput(g_tab[gi].nr_invites,u_tab[i].nickname);
-								if (g_tab[gi].mod > 0) {
-								   snprintf(line, LINE_SIZE, "%s invited",u_tab[i].nickname);
-								   sendstatus(g_tab[gi].mod, "FYI", line);
-								   }
-								snprintf(line, LINE_SIZE, "You are invited to group %s by default.", g_tab[gi].name);
-								sendstatus(i, "FYI", line);
+							    if (g_tab[gi].mod > 0) {
+							       snprintf(line, LINE_SIZE, "%s invited",u_tab[i].nickname);
+							       sendstatus(g_tab[gi].mod, "FYI", line);
+							   }
+							   snprintf(line, LINE_SIZE, "You are invited to group %s by default.", g_tab[gi].name);
+							   sendstatus(i, "FYI", line);
 							}
 						break;
 					case SET_MODERATE:
@@ -1056,7 +1056,7 @@
 				return;
 			}
 
-			strlcpy(g_tab[t_group].topic,fields[1],MAX_TOPICLEN);
+			strlcpy(g_tab[t_group].topic,fields[1],MAX_TOPICLEN+1);
 			if (g_tab[t_group].volume != QUIET) {
 			  snprintf(line, LINE_SIZE, "%s changed the topic to \"%s\"",
 				u_tab[n].nickname,
@@ -1210,12 +1210,12 @@
 	/* and change their group name entries */
 	for (i=0; i< MAX_REAL_USERS; i++) {
 		if (strcasecmp(u_tab[i].group, cp) == 0) {
-			strlcpy(u_tab[i].group, n_g_n, MAX_GROUPLEN);
+			strlcpy(u_tab[i].group, n_g_n, MAX_GROUPLEN+1);
 		}
 	}
 
 	/* finally change the name of the group itself */
-	strlcpy(g_tab[group].name, n_g_n, MAX_GROUPLEN);
+	strlcpy(g_tab[group].name, n_g_n, MAX_GROUPLEN+1);
 	return 0;
 }
 
