$NetBSD: patch-daemons_common_procfs.c,v 1.1.1.1 2012/03/21 20:48:53 asau Exp $

--- source/daemons/common/procfs.c.orig	2006-03-10 06:03:19.000000000 +0000
+++ source/daemons/common/procfs.c
@@ -338,6 +338,8 @@ void procfs_kill_addgrpid(gid_t add_grp_
        * uids[3], gids[3] => FSUID and FSGID
        */
       groups = 0;
+	/* silence gcc's -Werror */
+      uids[0] = uids[1] = gids[0] = gids[1] = 0;
       while (fgets(buffer, sizeof(buffer), fp)) {
          char *label = NULL;
          char *token = NULL;
