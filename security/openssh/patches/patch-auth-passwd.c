$NetBSD: patch-auth-passwd.c,v 1.3 2016/01/18 12:53:26 jperkin Exp $

Replace uid 0 with ROOTUID macro

--- auth-passwd.c.orig	2015-08-21 04:49:03.000000000 +0000
+++ auth-passwd.c
@@ -88,7 +88,7 @@ auth_password(Authctxt *authctxt, const 
 #endif
 
 #ifndef HAVE_CYGWIN
-	if (pw->pw_uid == 0 && options.permit_root_login != PERMIT_YES)
+	if (pw->pw_uid == ROOTUID && options.permit_root_login != PERMIT_YES)
 		ok = 0;
 #endif
 	if (*password == '\0' && options.permit_empty_passwd == 0)
@@ -123,7 +123,12 @@ auth_password(Authctxt *authctxt, const 
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
