$NetBSD: patch-drivers_dstate.c,v 1.1 2023/11/09 16:41:15 gdt Exp $

Cherry-pick upstream bugfix.

commit 2842201db26468a1eb1bf579e8b2fbf7538c5076
Author: Doug Nazar <nazard@nazar.ca>
Date:   Tue Nov 7 21:31:11 2023 -0500

    Fix SIGSEGV while preforming INSTCMD
    
    Parameter arg[2] is not guaranteed to be valid while preforming INSTCMD.
    Don't pass directly to main_instcmd().
    
    Signed-off-by: Doug Nazar <nazard@nazar.ca>

--- drivers/dstate.c
+++ drivers/dstate.c
@@ -780,7 +780,7 @@ static int sock_arg(conn_t *conn, size_t numarg, char **arg)
 			upsdebugx(3, "%s: TRACKING = %s", __func__, cmdid);
 
 		/* try the handler shared by all drivers first */
-		ret = main_instcmd(arg[1], arg[2], conn);
+		ret = main_instcmd(cmdname, cmdparam, conn);
 		if (ret != STAT_INSTCMD_UNKNOWN) {
 			/* The command was acknowledged by shared handler, and
 			 * either handled successfully, or failed, or was not
