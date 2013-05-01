$NetBSD: patch-auth-passwd.c,v 1.1 2013/05/01 19:58:26 imil Exp $

Replace uid 0 with ROOTUID macro

--- auth-passwd.c.orig	2012-04-25 23:51:28.000000000 +0000
+++ auth-passwd.c
@@ -87,7 +87,7 @@ auth_password(Authctxt *authctxt, const 
 #endif
 
 #ifndef HAVE_CYGWIN
-	if (pw->pw_uid == 0 && options.permit_root_login != PERMIT_YES)
+	if (pw->pw_uid == ROOTUID && options.permit_root_login != PERMIT_YES)
 		ok = 0;
 #endif
 	if (*password == '\0' && options.permit_empty_passwd == 0)
@@ -122,7 +122,12 @@ auth_password(Authctxt *authctxt, const 
 			authctxt->force_pwchange = 1;
 	}
 #endif
+
+#ifdef HAVE_INTERIX
+        result = (!setuser(pw->pw_name, password, SU_CHECK));
+#else
 	result = sys_auth_passwd(authctxt, password);
+#endif
 	if (authctxt->force_pwchange)
 		disable_forwarding();
 	return (result && ok);
