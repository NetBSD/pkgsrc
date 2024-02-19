$NetBSD: patch-channels_chan__oss.c,v 1.1 2024/02/19 05:59:51 jnemeth Exp $

--- channels/chan_oss.c.orig	2022-04-14 21:53:34.000000000 +0000
+++ channels/chan_oss.c
@@ -1317,7 +1317,7 @@ static void store_mixer(struct chan_oss_
 	int i;
 
 	for (i = 0; i < strlen(s); i++) {
-		if (!isalnum(s[i]) && strchr(" \t-/", s[i]) == NULL) {
+		if (!isalnum((unsigned char)s[i]) && strchr(" \t-/", s[i]) == NULL) {
 			ast_log(LOG_WARNING, "Suspect char %c in mixer cmd, ignoring:\n\t%s\n", s[i], s);
 			return;
 		}
