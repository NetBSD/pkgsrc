$NetBSD: patch-res_res__limit.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- res/res_limit.c.orig	2018-05-07 17:38:31.944908572 +0000
+++ res/res_limit.c
@@ -191,7 +191,7 @@ static char *handle_cli_ulimit(struct as
 				else
 					snprintf(printlimit, sizeof(printlimit), "limited to %d", (int) rlimit.rlim_cur);
 				desc = str2desc(a->argv[1]);
-				ast_cli(a->fd, "%c%s (%s) is %s.\n", toupper(desc[0]), desc + 1, a->argv[1], printlimit);
+				ast_cli(a->fd, "%c%s (%s) is %s.\n", toupper((unsigned char)desc[0]), desc + 1, a->argv[1], printlimit);
 			} else
 				ast_cli(a->fd, "Could not retrieve resource limits for %s: %s\n", str2desc(a->argv[1]), strerror(errno));
 			return CLI_SUCCESS;
