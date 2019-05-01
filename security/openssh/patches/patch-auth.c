$NetBSD: patch-auth.c,v 1.5 2019/05/01 17:59:56 maya Exp $

* Use login_getpwclass() instead of login_getclass() so that the root
  vs. default login class distinction is made correctly, from FrrrBSD's
  ports.

--- auth.c.orig	2019-05-01 11:28:52.028281617 +0000
+++ auth.c
@@ -599,7 +599,7 @@ getpwnamallow(struct ssh *ssh, const cha
 	if (!allowed_user(ssh, pw))
 		return (NULL);
 #ifdef HAVE_LOGIN_CAP
-	if ((lc = login_getclass(pw->pw_class)) == NULL) {
+	if ((lc = login_getpwclass(pw->pw_class)) == NULL) {
 		debug("unable to get login class: %s", user);
 		return (NULL);
 	}
