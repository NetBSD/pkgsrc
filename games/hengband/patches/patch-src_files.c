$NetBSD: patch-src_files.c,v 1.1 2023/11/24 01:59:33 pho Exp $

Fix an alignment issue in the player info screen. TODO: Upstream this.

--- src/files.c.orig	2023-11-23 20:34:32.289742087 +0000
+++ src/files.c
@@ -3202,7 +3202,7 @@ display_flag_aux(row+9, col, "呪い    
 	display_flag_aux(row+0, col, "Speed     :", TR_SPEED, &f, 0);
 	display_flag_aux(row+1, col, "FreeAction:", TR_FREE_ACT, &f, 0);
 	display_flag_aux(row+2, col, "SeeInvisi.:", TR_SEE_INVIS, &f, 0);
-	display_flag_aux(row+3, col, "Hold Exp :", TR_HOLD_EXP, &f, 0);
+	display_flag_aux(row+3, col, "Hold Exp  :", TR_HOLD_EXP, &f, 0);
 	display_flag_aux(row+4, col, "Warning   :", TR_WARNING, &f, 0);
 	display_flag_aux(row+5, col, "SlowDigest:", TR_SLOW_DIGEST, &f, 0);
 	display_flag_aux(row+6, col, "Regene.   :", TR_REGEN, &f, 0);
