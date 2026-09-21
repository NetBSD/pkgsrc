$NetBSD: patch-src_helper_command.c,v 1.1 2026/09/21 11:37:52 bouyer Exp $

Fix build with jimtcl 0.84.

--- src/helper/command.c.orig	2026-09-20 23:24:01.082032876 +0200
+++ src/helper/command.c	2026-09-20 23:26:01.586476179 +0200
@@ -48,17 +48,18 @@
 /* set of functions to wrap jimtcl internal data */
 static inline bool jimcmd_is_proc(Jim_Cmd *cmd)
 {
-	return cmd->isproc;
+	return ((cmd->flags & JIM_CMD_ISPROC) != 0);
+
 }
 
 bool jimcmd_is_oocd_command(Jim_Cmd *cmd)
 {
-	return !cmd->isproc && cmd->u.native.cmdProc == jim_command_dispatch;
+	return !jimcmd_is_proc(cmd) && cmd->u.native.cmdProc == jim_command_dispatch;
 }
 
 void *jimcmd_privdata(Jim_Cmd *cmd)
 {
-	return cmd->isproc ? NULL : cmd->u.native.privData;
+	return jimcmd_is_proc(cmd) ? NULL : cmd->u.native.privData;
 }
 
 static void tcl_output(void *privData, const char *file, unsigned line,
