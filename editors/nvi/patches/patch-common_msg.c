$NetBSD: patch-common_msg.c,v 1.1 2015/05/11 08:43:44 enami Exp $

--- common/msg.c.orig	2007-11-18 16:41:42.000000000 +0000
+++ common/msg.c
@@ -640,7 +640,8 @@ msgq_status(SCR *sp, db_recno_t lno, u_i
 			p += len;
 		} else {
 			t = msg_cat(sp, "027|line %lu of %lu [%ld%%]", &len);
-			(void)sprintf(p, t, lno, last, (lno * 100) / last);
+			(void)sprintf(p, t, (u_long)lno, (u_long)last,
+			    (long)((lno * 100) / last));
 			p += strlen(p);
 		}
 	} else {
