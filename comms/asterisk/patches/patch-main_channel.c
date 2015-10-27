$NetBSD: patch-main_channel.c,v 1.1 2015/10/27 08:49:01 jnemeth Exp $

--- main/channel.c.orig	2015-10-24 19:56:31.000000000 +0000
+++ main/channel.c
@@ -5907,15 +5907,8 @@ static int set_security_requirements(con
 	ast_channel_unlock(r);
 
 	for (i = 0; i < 2; i++) {
-		if (ops[i][1]) {
-			if (ast_channel_setoption(out, ops[i][0], &ops[i][1], sizeof(ops[i][1]), 0)) {
-				/* We require a security feature, but the channel won't provide it */
-				return -1;
-			}
-		} else {
-			/* We don't care if we can't clear the option on a channel that doesn't support it */
-			ast_channel_setoption(out, ops[i][0], &ops[i][1], sizeof(ops[i][1]), 0);
-		}
+		/* We don't care if we can't clear the option on a channel that doesn't support it */
+		ast_channel_setoption(out, ops[i][0], &ops[i][1], sizeof(ops[i][1]), 0);
 	}
 
 	return 0;
