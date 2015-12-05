$NetBSD: patch-funcs_func__env.c,v 1.1.1.1 2015/12/05 23:29:10 jnemeth Exp $

--- funcs/func_env.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ funcs/func_env.c
@@ -309,7 +309,7 @@ static int stat_read(struct ast_channel 
 			snprintf(buf, len, "%d", (int) s.st_ctime);
 			break;
 		case 'm':
-			snprintf(buf, len, "%o", s.st_mode);
+			snprintf(buf, len, "%o", (unsigned int) s.st_mode);
 			break;
 		}
 	}
