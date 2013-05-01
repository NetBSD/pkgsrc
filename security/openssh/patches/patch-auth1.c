$NetBSD: patch-auth1.c,v 1.1 2013/05/01 19:58:26 imil Exp $

Replace uid 0 with ROOTUID macro

--- auth1.c.orig	2012-12-02 22:53:20.000000000 +0000
+++ auth1.c
@@ -321,7 +321,7 @@ do_authloop(Authctxt *authctxt)
 
 #ifndef HAVE_CYGWIN
 		/* Special handling for root */
-		if (authenticated && authctxt->pw->pw_uid == 0 &&
+		if (authenticated && authctxt->pw->pw_uid == ROOTUID &&
 		    !auth_root_allowed(meth->name)) {
  			authenticated = 0;
 # ifdef SSH_AUDIT_EVENTS
@@ -425,8 +425,8 @@ do_authentication(Authctxt *authctxt)
 	 * If we are not running as root, the user must have the same uid as
 	 * the server.
 	 */
-#ifndef HAVE_CYGWIN
-	if (!use_privsep && getuid() != 0 && authctxt->pw &&
+#if !defined(HAVE_CYGWIN) && !defined(HAVE_INTERIX)
+	if (!use_privsep && getuid() != ROOTUID && authctxt->pw &&
 	    authctxt->pw->pw_uid != getuid())
 		packet_disconnect("Cannot change user when server not running as root.");
 #endif
