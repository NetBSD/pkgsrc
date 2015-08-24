$NetBSD: patch-auth2.c,v 1.3.12.2 2015/08/24 19:06:40 tron Exp $

Replace uid 0 with ROOTUID macro

--- auth2.c.orig	2015-07-01 02:35:31.000000000 +0000
+++ auth2.c
@@ -302,7 +302,7 @@ userauth_finish(Authctxt *authctxt, int 
 		fatal("INTERNAL ERROR: authenticated and postponed");
 
 	/* Special handling for root */
-	if (authenticated && authctxt->pw->pw_uid == 0 &&
+	if (authenticated && authctxt->pw->pw_uid == ROOTUID &&
 	    !auth_root_allowed(method)) {
 		authenticated = 0;
 #ifdef SSH_AUDIT_EVENTS
