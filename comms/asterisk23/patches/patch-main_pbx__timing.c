$NetBSD: patch-main_pbx__timing.c,v 1.1 2025/10/27 06:58:39 jnemeth Exp $

--- main/pbx_timing.c.orig	2018-05-07 17:30:09.949079213 +0000
+++ main/pbx_timing.c
@@ -137,7 +137,7 @@ static void get_timerange(struct ast_tim
 		}
 		*endpart++ = '\0';
 		/* why skip non digits? Mostly to skip spaces */
-		while (*endpart && !isdigit(*endpart)) {
+		while (*endpart && !isdigit((unsigned char)*endpart)) {
 			endpart++;
 		}
 		if (!*endpart) {
