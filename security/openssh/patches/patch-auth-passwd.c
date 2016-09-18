$NetBSD: patch-auth-passwd.c,v 1.4 2016/09/18 17:30:11 taca Exp $

Replace uid 0 with ROOTUID macro

--- auth-passwd.c.orig	2016-07-27 22:54:27.000000000 +0000
+++ auth-passwd.c
@@ -93,7 +93,7 @@ auth_password(Authctxt *authctxt, const 
 		return 0;
 
 #ifndef HAVE_CYGWIN
-	if (pw->pw_uid == 0 && options.permit_root_login != PERMIT_YES)
+	if (pw->pw_uid == ROOTUID && options.permit_root_login != PERMIT_YES)
 		ok = 0;
 #endif
 	if (*password == '\0' && options.permit_empty_passwd == 0)
@@ -128,7 +128,12 @@ auth_password(Authctxt *authctxt, const 
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
