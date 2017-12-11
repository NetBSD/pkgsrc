$NetBSD: patch-src_s__group.c,v 1.1 2017/12/11 07:54:42 spz Exp $

fix copy lengths

--- src/s_group.c.orig	2006-05-11 03:44:53.000000000 +0000
+++ src/s_group.c
@@ -260,7 +260,7 @@ s_change(int n, int argc)
 			}
 			/* could create it, so fill in the info */
 			g_tab[ngi].visibility = visibility;
-			strlcpy(g_tab[ngi].name, n_g_n, MAX_GROUPLEN);
+			strlcpy(g_tab[ngi].name, n_g_n, MAX_GROUPLEN+1);
 			if (strcasecmp("1", n_g_n) != 0) {
 				g_tab[ngi].control = MODERATED;
 				g_tab[ngi].mod = n;
@@ -326,7 +326,7 @@ s_change(int n, int argc)
 		/* is the new group different than the old group? */
 		if (ngi != ogi) {
 			/* the group exists and we are allowed in. */
-			strlcpy(u_tab[n].group, g_tab[ngi].name, MAX_GROUPLEN);
+			strlcpy(u_tab[n].group, g_tab[ngi].name, MAX_GROUPLEN+1);
 
 			/* tell the new group about the arrival */
 			snprintf(line, LINE_SIZE, "%s (%s@%s) entered group", u_tab[n].nickname,
@@ -1056,7 +1056,7 @@ s_topic(int n, int argc)
 				return;
 			}
 
-			strlcpy(g_tab[t_group].topic,fields[1],MAX_TOPICLEN);
+			strlcpy(g_tab[t_group].topic,fields[1],MAX_TOPICLEN+1);
 			if (g_tab[t_group].volume != QUIET) {
 			  snprintf(line, LINE_SIZE, "%s changed the topic to \"%s\"",
 				u_tab[n].nickname,
@@ -1210,12 +1210,12 @@ set_name(int n, int group, char *name)
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
 
