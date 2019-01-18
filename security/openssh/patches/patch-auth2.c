$NetBSD: patch-auth2.c,v 1.7 2019/01/18 20:13:37 tnn Exp $

Replace uid 0 with ROOTUID macro

--- auth2.c.orig	2018-10-17 00:01:20.000000000 +0000
+++ auth2.c
@@ -352,7 +352,7 @@ userauth_finish(struct ssh *ssh, int aut
 		fatal("INTERNAL ERROR: authenticated and postponed");
 
 	/* Special handling for root */
-	if (authenticated && authctxt->pw->pw_uid == 0 &&
+	if (authenticated && authctxt->pw->pw_uid == ROOTUID &&
 	    !auth_root_allowed(ssh, method)) {
 		authenticated = 0;
 #ifdef SSH_AUDIT_EVENTS
