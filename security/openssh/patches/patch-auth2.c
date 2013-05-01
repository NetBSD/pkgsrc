$NetBSD: patch-auth2.c,v 1.1 2013/05/01 19:58:26 imil Exp $

Replace uid 0 with ROOTUID macro

--- auth2.c.orig	2012-12-02 22:53:20.000000000 +0000
+++ auth2.c
@@ -307,7 +307,7 @@ userauth_finish(Authctxt *authctxt, int 
 		fatal("INTERNAL ERROR: authenticated and postponed");
 
 	/* Special handling for root */
-	if (authenticated && authctxt->pw->pw_uid == 0 &&
+	if (authenticated && authctxt->pw->pw_uid == ROOTUID &&
 	    !auth_root_allowed(method)) {
 		authenticated = 0;
 #ifdef SSH_AUDIT_EVENTS
