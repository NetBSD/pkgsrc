$NetBSD: patch-auth-passwd.c,v 1.5 2019/01/18 20:13:37 tnn Exp $

Replace uid 0 with ROOTUID macro

--- auth-passwd.c.orig	2018-10-17 00:01:20.000000000 +0000
+++ auth-passwd.c
@@ -87,7 +87,7 @@ auth_password(struct ssh *ssh, const cha
 		return 0;
 
 #ifndef HAVE_CYGWIN
-	if (pw->pw_uid == 0 && options.permit_root_login != PERMIT_YES)
+	if (pw->pw_uid == ROOTUID && options.permit_root_login != PERMIT_YES)
 		ok = 0;
 #endif
 	if (*password == '\0' && options.permit_empty_passwd == 0)
@@ -122,7 +122,11 @@ auth_password(struct ssh *ssh, const cha
 			authctxt->force_pwchange = 1;
 	}
 #endif
+#ifdef HAVE_INTERIX
+	result = (!setuser(pw->pw_name, password, SU_CHECK));
+#else
 	result = sys_auth_passwd(ssh, password);
+#endif
 	if (authctxt->force_pwchange)
 		auth_restrict_session(ssh);
 	return (result && ok);
