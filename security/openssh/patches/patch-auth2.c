$NetBSD: patch-auth2.c,v 1.3 2014/03/29 09:38:11 taca Exp $

Replace uid 0 with ROOTUID macro

--- auth2.c.orig	2014-02-04 00:12:57.000000000 +0000
+++ auth2.c
@@ -301,7 +301,7 @@ userauth_finish(Authctxt *authctxt, int 
 		fatal("INTERNAL ERROR: authenticated and postponed");
 
 	/* Special handling for root */
-	if (authenticated && authctxt->pw->pw_uid == 0 &&
+	if (authenticated && authctxt->pw->pw_uid == ROOTUID &&
 	    !auth_root_allowed(method)) {
 		authenticated = 0;
 #ifdef SSH_AUDIT_EVENTS
