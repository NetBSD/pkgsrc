$NetBSD: patch-pam__af__tool_pam__af__tool.c,v 1.1 2014/12/21 07:31:15 obache Exp $

* fixed array will never be NULL. check the first element instead. 

--- pam_af_tool/pam_af_tool.c.orig	2011-08-24 07:53:32.000000000 +0000
+++ pam_af_tool/pam_af_tool.c
@@ -722,11 +722,11 @@ handle_rulelist(argc, argv)
 
 		printf("\t\t<locktime>%ldS</locktime>\n", hstent->locktime);
 
-		if (hstent->lock_cmd != NULL)
+		if (*hstent->lock_cmd != 0)
 			printf("\t\t<lockcmd>%s</lockcmd>\n", \
 			    hstent->lock_cmd);
 
-		if (hstent->unlock_cmd != NULL)
+		if (*hstent->unlock_cmd != 0)
 			printf("\t\t<unlockcmd>%s</unlockcmd>\n", \
 			    hstent->unlock_cmd);
 
@@ -1237,7 +1237,7 @@ lock_host(host, force)
 	    ((hstrec.num >= hstent->attempts) || force != 0)) {
 		hstrec.locked_for = hstent->locktime;
 		hstrec.last_attempt = time(NULL);
-		if (hstent->lock_cmd != NULL)
+		if (*hstent->lock_cmd != 0)
 			(void)exec_cmd(hstent->lock_cmd, env);
 
 		/* Free asprintf-allocated buffer */
@@ -1326,7 +1326,7 @@ unlock_host(host, force)
 	    force != 0) && hstrec.locked_for != 0) {
 		hstrec.locked_for = 0;
 		hstrec.num = 0;
-		if (hstent->unlock_cmd != NULL)
+		if (*hstent->unlock_cmd != 0)
 			(void)exec_cmd(hstent->unlock_cmd, env);
 
 		/* Free asprintf-allocated buffer */
