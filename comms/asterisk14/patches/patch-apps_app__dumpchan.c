$NetBSD: patch-apps_app__dumpchan.c,v 1.1.1.1 2016/10/25 08:17:07 jnemeth Exp $

--- apps/app_dumpchan.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ apps/app_dumpchan.c
@@ -117,7 +117,7 @@ static int serialize_showchan(struct ast
 		"1stFileDescriptor=  %d\n"
 		"Framesin=           %u %s\n"
 		"Framesout=          %u %s\n"
-		"TimetoHangup=       %ld\n"
+		"TimetoHangup=       %jd\n"
 		"ElapsedTime=        %dh%dm%ds\n"
 		"BridgeID=           %s\n"
 		"Context=            %s\n"
@@ -155,7 +155,7 @@ static int serialize_showchan(struct ast
 		ast_channel_fd(c, 0),
 		ast_channel_fin(c) & ~DEBUGCHAN_FLAG, (ast_channel_fin(c) & DEBUGCHAN_FLAG) ? " (DEBUGGED)" : "",
 		ast_channel_fout(c) & ~DEBUGCHAN_FLAG, (ast_channel_fout(c) & DEBUGCHAN_FLAG) ? " (DEBUGGED)" : "",
-		(long)ast_channel_whentohangup(c)->tv_sec,
+		(intmax_t)ast_channel_whentohangup(c)->tv_sec,
 		hour,
 		min,
 		sec,
