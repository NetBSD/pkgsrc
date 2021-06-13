$NetBSD: patch-funcs_func__channel.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- funcs/func_channel.c.orig	2018-05-07 17:22:10.785599288 +0000
+++ funcs/func_channel.c
@@ -492,7 +492,7 @@ static int func_channel_write_real(struc
 	} else if (!strcasecmp(data, "amaflags")) {
 		int amaflags;
 
-		if (isdigit(*value)) {
+		if (isdigit((unsigned char)*value)) {
 			if (sscanf(value, "%30d", &amaflags) != 1) {
 				amaflags = AST_AMA_NONE;
 			}
