$NetBSD: patch-auth2.c,v 1.1.4.1 2013/12/05 09:52:53 tron Exp $

Replace uid 0 with ROOTUID macro

--- auth2.c.orig	2013-06-01 21:41:51.000000000 +0000
+++ auth2.c
@@ -310,7 +310,7 @@ userauth_finish(Authctxt *authctxt, int 
 		fatal("INTERNAL ERROR: authenticated and postponed");
 
 	/* Special handling for root */
-	if (authenticated && authctxt->pw->pw_uid == 0 &&
+	if (authenticated && authctxt->pw->pw_uid == ROOTUID &&
 	    !auth_root_allowed(method)) {
 		authenticated = 0;
 #ifdef SSH_AUDIT_EVENTS
